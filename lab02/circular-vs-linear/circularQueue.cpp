#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  if(head == tail)
    return true; // dummy return
  return false;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  if((tail+1)%N == head)
    return true; // dummy return
  return false;
}

template <typename T> void DynamicQueue<T> :: grow() {
  unsigned int old_size = N;
  N = nextSize();
  T* tmpA = new T[N];
  for(int i=0; i<old_size; i++){
    tmpA[i] = A[(head+i)%old_size];
  }
  delete[] A;
  A = tmpA;
  head = 0; tail = head + old_size;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (N-head+tail)%N; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()){
    grow();
  }
    A[tail]=x;
    tail=(tail+1)%N;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()){
    return false;
  }
  *x = A[head];
  head = (head+1)%N;
  return true; // dummy return
}
