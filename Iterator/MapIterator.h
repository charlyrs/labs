#ifndef ITERATOR_MAPITERATOR_H
#define ITERATOR_MAPITERATOR_H
#include "Iterator.h"
#include <map>
#include <string>
#include <iterator>
#include <vector>
//#include <pair>

template <typename T>
class MapIterator : Iterator<T>{
    std::vector<std::pair<std::string, T>> pairs;
    int index = 0;
public:
    MapIterator(std::map<std::string, T> data, std::string required_key_substring){
        auto  iter = data.begin();
        while (iter!= data.end()){
            if(iter->first.find(required_key_substring)!= std::string::npos){
                pairs.push_back(std::make_pair(iter->first, iter->second));
            }
            iter++;
        }

    }
    T first() override {
       index = 0;
       return pairs[0].second;
    }
    bool is_done() override {
        return index == pairs.size();
    }
    void next() override {
        if(index == pairs.size()){
            throw std::exception("Array is out of range");
        }
        index++;
    }
    T current_item() override {
        if(index == pairs.size()){
            throw std::exception("Array is out of range");
        }

        return pairs[index].second;
    }

};
#endif //ITERATOR_MAPITERATOR_H
