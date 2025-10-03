#include "dictionary.h"

//Implement dictionary here

#define TOMBSTONE (char*)0xabcdabcdabcdabcd
#define factor 31
#define alpha 0.6180339887

Dictionary::Dictionary(){
    N=DICT_SIZE;
    A = new Entry[N];
};

Dictionary::~Dictionary(){
    delete[] A;
}

int Dictionary::hashValue(char key[]){
    
    /*** For testcases compliance use factor: 31
    and alpha: 0.6180339887 in your implementation 
    but you are free to use other values and see variation in hash plots ***/
    
    double fracHashValue = 0;
    for (int i = strlen(key) - 1; i >= 0; i--)
    {
        fracHashValue *= factor;
        fracHashValue += alpha * key[i];
        fracHashValue -= int(fracHashValue);
    }
    return int(N * fracHashValue);
}

int Dictionary::findFreeIndex(char key[]){
    int ind = hashValue(key); 
    int firstX = -1;
    for(int i=0;i<N;i++){
        if(A[ind].key==TOMBSTONE && firstX==-1){
            firstX = ind;
        }
        if(A[ind].key==nullptr) return (firstX != -1) ? firstX : ind;
        if(A[ind].key!=TOMBSTONE && strcmp(A[ind].key, key) == 0){
            return ind;
        }
        ind++; ind%=N;
    }
    return (firstX != -1) ? firstX : -1;
}

struct Entry* Dictionary::get(char key[]){
    int ind = hashValue(key);
    for(int i=0;i<N;i++){
        if(A[ind].key==nullptr) break;
        if(A[ind].key != TOMBSTONE && strcmp(A[ind].key,key)==0) return &A[ind];
        ind++; ind%=N;
    }
    return nullptr;
}

bool Dictionary::put(Entry e) {
    int ind = findFreeIndex(e.key);
    if(ind>=0) {
        if (A[ind].key != nullptr && A[ind].key != TOMBSTONE){
            delete[] A[ind].key;
        }
        int len = strlen(e.key);
        A[ind].key = new char[len + 1];
        strcpy(A[ind].key, e.key);
        A[ind].value = e.value;
        return true;
    }
    return false;
}

bool Dictionary::remove(char key[]){
    Entry* e = get(key);
    if(e!=nullptr && e->key!=nullptr){delete[] e->key;e->key = TOMBSTONE; return true;}
    return false;
}