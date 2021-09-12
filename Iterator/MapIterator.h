#ifndef ITERATOR_MAPITERATOR_H
#define ITERATOR_MAPITERATOR_H
#include "Iterator.h"
#include <map>
#include <string>
#include <iterator>
#include <vector>

template <typename T>
class MapIterator : Iterator<T>{
    std::vector<std::string> keys;
    std::map<std::string, T> map;
    int index = 0;
public:
    MapIterator(std::map<std::string, T> data, std::string required_key_substring){
        auto  iter = data.begin();
        map = data;
        while (iter!= data.end()){
            if(iter->first.find(required_key_substring)!= std::string::npos){
                keys.push_back(iter->first);
            }
            iter++;
        }

    }
    T first() override {
       index = 0;
       return map.find(keys[0])->second;
    }
    bool is_done() override {
        return index == keys.size();
    }
    void next() override {
        if(index == keys.size()){
            throw std::exception("Array is out of range");
        }
        index++;
    }
    T current_item() override {
        if(index == keys.size()){
            throw std::exception("Array is out of range");
        }

        return map.find(keys[index])->second;
    }

};
#endif //ITERATOR_MAPITERATOR_H
