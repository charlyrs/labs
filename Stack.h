
#ifndef LAB8_STACK_H
#define LAB8_STACK_H

template<typename T>
class Stack {
private:
    T* data;
    int topID;
    int size;
    int capacity;

public:
    Stack();
    Stack(int capacity);
    void push(T );
    T pop();
    T peak();
    ~Stack();
    void operator << (T );
    T operator >> (T& );
    Stack<T>& operator = (const Stack<T>&);
    bool operator== (const Stack<T>&a);
    bool operator!= (const Stack<T>&a);
    bool operator < (const Stack<T>&) const;
    bool operator > (const Stack<T>&) const;
    void ExtendCapacity();
    T operator[](int);
    int Size();
};


#endif //LAB8_STACK_H
