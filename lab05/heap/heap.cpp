#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION
*/


#include "heap.h"

// gives us the index of the parent for the element at index 'i'
int Heap::parent(int i)
{
return (i-1)/2; // dummy return
}


// gives us the index of the left child for the element at index 'i'
int Heap::left(int i)
{
return 2*i+1; // dummy return
}


// gives us the index of the right child for the element at index 'i'
int Heap::right(int i)
{
return 2*i+2; //dummy
}


// gives us the maximum element in the heap
int Heap::max()
{
return store[0]; //dummy
}


//swaps the elements at indices 'i' and 'j' in the store array
// Do not forget to increment the swap_count
void Heap::swap(int i, int j)
{
auto tmp = store[i];
store[i]=store[j];
store[j]=tmp;
swap_count++;
}


// inserts elements into the store array
// can use the helper function append in heap.h
void Heap::insert(int v)
{
append(v);
int idx_v=size()-1;
while(store[parent(idx_v)]<store[idx_v]){
swap(idx_v,parent(idx_v));
idx_v=parent(idx_v);
}
}

// makes the subtree rooted at index 'i' follow the Max Heap property
// HINT: calls the swap and recusively goes down the subtree
void Heap::heapify(int i)
{
int max;
if(left(i)>size()-1) return;
else if(right(i)>size()-1) max = left(i);
else{
max=store[left(i)]>=store[right(i)]?left(i):right(i);
}
max = store[max]>=store[i]?max:i;
if(max==i) return;
else{
swap(max,i);
heapify(max);
}
}

// deletes the maximum element and makes the remaining tree follow the max heap property
// HINT: calls the heapify
void Heap::deleteMax()
{
swap(0,size()-1);
removeLast();
heapify(0);
}


// rearranges the array such that it follows the max heap property
// HINT: calls the heapify
// HINT: for efiicient building follow a bottom-up approach
void Heap::buildHeap()
{
int curr_idx=size()-1;
while(curr_idx>=0){
heapify(curr_idx);
curr_idx--;
}
}


// used to arrange the elements in descending order
// The sorted elemendts must be stored in the 'store' array
// Can use a temporary vector to sort
// HINT: Since you are using a temporary vector to sort, make sure to apply the heapify logic on that temporary vector
// and also increment the swap count whenever you perform a swap
void Heap::heapSort()
{
std::vector<int> v(size());
int j=0;
while(size()>0){
v[j]=max();
deleteMax();
j++;
}
for(int i=0;i<j;i++){
store[i]=v[i];
}
sz=j;
}