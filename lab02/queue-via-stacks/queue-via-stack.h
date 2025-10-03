// WRITE IMPLEMENTATIONS OF METHODS BELOW

#include "queue.h"

template <typename T>
Queue<T>::Queue() {
}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::enqueue(T value){
    // if(first_stack.isEmpty()) {
    //     while(!second_stack.isEmpty()){
    //         first_stack.push(second_stack.peek());
    //         second_stack.pop();
    //     }
    // }
    first_stack.push(value);
}

template <typename T>
T Queue<T>::dequeue(){
    if(isEmpty()){
        throw "Empty Queue Dequeue Error";
    }
    T var;
    if(second_stack.isEmpty()){
        while(!first_stack.isEmpty()){
            second_stack.push(first_stack.pop());
        }
    }
    var = second_stack.pop();
    return var;
}

template <typename T>
T Queue<T>::peek() {
    if(isEmpty()) throw "Empty Queue Peek Error";
    T var;
    if(second_stack.isEmpty()){
        while(!first_stack.isEmpty()){
            second_stack.push(first_stack.pop());
        }
    }
    var = second_stack.peek();
    return var;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return first_stack.isEmpty() && second_stack.isEmpty();
}

template <typename T>
size_t Queue<T>::getSize() {
    return first_stack.getSize() + second_stack.getSize();
}
