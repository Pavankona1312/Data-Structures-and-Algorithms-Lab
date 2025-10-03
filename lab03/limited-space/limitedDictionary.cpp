#include "dictionary.h"
#include <stdexcept>
#include "limitedDictionary.h"
#include<iostream>

LimitedDictionary::LimitedDictionary(int capacity, Policy policy): Dictionary(capacity){
    if(capacity < 1){
        throw std::runtime_error("Cannot create dictionary with capacity less than 1");
    }
    else{
        // Initialize the Limited Dictionary
        this->policy = policy;
        this->capacity = capacity;
        this->size = 0;
        // YOUR CODE HERE
    }
}

void LimitedDictionary::evict_fifo(){
    // Implement the FIFO eviction scheme
    auto e = get(q.front());
    bool tmp = remove(e->key);
    q.pop();
    // YOUR CODE HERE
    // Make sure to flush the evicted key into std::cerr for testing
    // Modify this part
    std::string evicted_key = e->key;
    std::cerr << "evicted: " << evicted_key << std::endl;
}

void LimitedDictionary::insert_fifo(struct Entry e){
    // Implement the FIFO insertion scheme
    // YOUR CODE HERE
    q.push(e.key);
    // Make sure to flush the inserted key into std::cerr for testing
    // Don't delete this line
    std::cerr << "inserted: " << e.key << std::endl;
}


void LimitedDictionary::init_lru(){
    // Initialize variables for LRU scheme
    
    // YOUR CODE HERE
}

void LimitedDictionary::evict_lru(){
    // Implement the LRU eviction scheme


    // YOUR CODE HERE


    // Make sure to flush the evicted key into std::cerr for testing
    // Modify this part
    std::string evicted_key = "";
    // std::cerr << "evicted: " << evicted_key << std::endl;
}

void LimitedDictionary::insert_lru(struct Entry e){
    // Implement the LRU insertion scheme


    // YOUR CODE HERE


    // Make sure to flush the inserted key into std::cerr for testing
    // Don't delete this line
    // std::cerr << "inserted: " << e.key << std::endl;
}


bool LimitedDictionary::put(struct Entry e) {
    // Overload the put function from original Dictionary
    if(policy==FIFO){
        bool tmp = Dictionary::put(e);
        if(!tmp){
            evict_fifo();
        }
        tmp = Dictionary::put(e);
        insert_fifo(e);
    }
    return true;
}

bool LimitedDictionary::remove(std::string key){
    // Overload the remove function from original Dictionary

    // YOUR CODE HERE
    return 0;
}

struct Entry* LimitedDictionary::get(std::string key){
    // Overload the get function from original Dictionary
    // YOUR CODE HERE
    return Dictionary::get(key);
}
