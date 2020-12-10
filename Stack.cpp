#include "Stack.h"
#include <iostream>
template<typename T>
Stack<T>::Stack() {
    size = 0;
    capacity = 20;
    data = new T[capacity];
    topID = -1;
}
template <typename T>
void Stack<T>::ExtendCapacity() {
  capacity*=2;
  T* tempdata = new T [capacity];
  for (int i = 0; i < size; ++i) {
    tempdata[i]=data[i];
  }
  delete [] data;
  data=tempdata;
}

template<typename T>
Stack<T>::Stack(int capacity) {
    size = 0;
    this->capacity = capacity;
    data = new T[capacity];
    topID = -1;
}

template<typename T>
void Stack<T>::push(T a) {
    if (size == capacity) {
        ExtendCapacity();
    }
    size++;
    data[++topID] = a;
}
template<typename T>
T Stack<T>::pop() {
    if (size == 0) {
        throw std::underflow_error("Stack is empty");
    }
    T value = data[topID];
    topID--;
    size--;
    return value;
}
template<typename T>
T Stack<T>::peak() {
    if (size==0) throw "aaaa";
    return data[topID];
}
template<typename T>
Stack<T>::~Stack() {
    delete[] data;
}
template<typename T>
void Stack<T>::operator<<(T a) {
    push(a);
}
template<typename T>
T Stack<T>::operator>>(T &a) {
    a = data[topID];
    return pop();
}
template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &q) {
    if (this==&q){
    return *this;
    }
    delete[] data;
    capacity = q.capacity;
    data = new T[capacity];
    int i = 0;
    for (; i < q.size; ++i) {
        push(q.data[i]);
    }
    topID = i - 1;
    size = i ;
    return *this;
}
template<typename T>
bool Stack<T>::operator==(const Stack<T> &a) {
    if (size!=a.size) return false;
    int count=0;
    for (int i=0;i<size; ++i){
        if(data[i]==a.data[i]) count++;
    }
    if (count==size) return true;
    else return false;
}
template<typename T>
bool Stack<T>::operator!=(const Stack<T> &a) {
    return !(this->operator==(a));
}
template<typename T>
bool Stack<T>::operator<(const Stack<T> &a) const { // I've got no idea how to compare stacks so...
    bool result = (size < a.size);
    return result;
}
template<typename T>
bool Stack<T>::operator>(const Stack<T> &a) const  {
    bool result = (size > a.size);
    return result;
}
template<typename T>
T Stack<T>::operator[](int i) {
    return data[i];
}
template<typename T>
int Stack<T>::Size() {
    return size;
}
template class Stack<int>;
template class Stack<char>;
template class Stack<double>;