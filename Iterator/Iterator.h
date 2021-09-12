#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H
template<typename T>
class Iterator {
public:
    virtual T first() = 0;
    virtual void next() = 0;
    virtual T current_item() = 0;
    virtual bool is_done() = 0;
};
#endif //ITERATOR_ITERATOR_H
