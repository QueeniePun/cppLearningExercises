#ifndef STACK_H
#define STACK_H

class StackOfIntegers
{
public:
    StackOfIntegers();
    bool isEmpty() const;
    int peek() const;
    void push(int value);
    int pop();
    int getSize() const;

    int& operator[](int index);
private:
    int elements[100];
    int size; 
};

#endif