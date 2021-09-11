#ifndef ITERATOR_ARRAYITERATOR_H
#define ITERATOR_ARRAYITERATOR_H
#include "Iterator.h"
#include "exception"
template <typename T>
class ArrayIterator : Iterator<T> {
    T* data;
    int _size;
    int index;
public:
    ArrayIterator(T* data, int size){
        index = 0;
        _size = size;
        this->data = data;
    };
    T first() override {
        index = 0;
        return data[0];
    }
    bool is_done() override {
        return index == _size;
    }
    void next() override {
        if(index == _size){
            throw std::exception("Array is out of range");
        }
        index++;
    }
    T current_item() override {
        if(index == _size){
            throw std::exception("Array is out of range");
        }
        return data[index];
    }

};
#endif //ITERATOR_ARRAYITERATOR_H
