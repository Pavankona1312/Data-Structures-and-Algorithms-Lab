#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return !((N+tail-head)%N); // dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return !((head-1-tail+N)%N); // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
    auto tmp = size();
    auto old_size = N;
      N = nextSize();
    T* temp=new T[N];
  for(int i=0;i<old_size;i++) {
    temp[i]=A[(i+head)%old_size];
  }
  delete[] A;
  A=temp;
  head=0;
  tail=tmp;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (tail-head+N)%N; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()) grow();
  A[tail]=x;
  tail=(tail+1)%N;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false;
  *x = A[head];
  head=(head+1)%N;
  return true; // dummy return
}