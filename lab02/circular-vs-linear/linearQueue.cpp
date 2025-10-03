#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  if(head == tail)
    return true; // dummy return
  return false;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  if(tail+1==N)
  return true;
  else
   return false; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  auto old_size = size();
  N = nextSize();
  T* tmp = new T[N];
  for(int i=head;i<N;i++){
    tmp[i-head] = A[i];
  }
  delete[] A;
  A = tmp;
  head=0;
  tail=old_size;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return tail-head; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()){
    grow();
  }
  tail+=1;
  A[tail] = x;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false; 
  *x = A[head];
  head++;
  return true;
}
