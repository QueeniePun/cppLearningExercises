#ifndef GENERICSTACK_H
#define GENERICSTACK_H

using namespace std; 

template<typename T> 
class Stack
{
public: 
    Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;
private:
    T elements[100];
    int size; 
};

#endif