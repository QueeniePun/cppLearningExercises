#pragma once
#include "LinkedList.h"
using namespace std;


template<typename T>
class LinkedListStack: public LinkedList<T>
{
public:
    LinkedListStack();
    LinkedListStack(LinkedListStack& stack);
    ~LinkedListStack();
    bool empty() const;
    T peek() const; 
    void push(T value); 
    T pop();

private:

    using LinkedList<T>::head_;
    using LinkedList<T>::tail_;
    using LinkedList<T>::size_;

};

template<typename T> 
LinkedListStack<T>::LinkedListStack()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

template<typename T> 
LinkedListStack<T>::LinkedListStack(LinkedListStack &stack)
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;

}


template<typename T> 
LinkedListStack<T>::~LinkedListStack()
{
    this->clear();
}


template<typename T> 
T LinkedListStack<T>::peek() const
{
    if (head_ == NULL)
    {
        throw runtime_error("Error in peek(): LinkedListStack is empty");
    }
    Node<T>* temp = head_; 

    return temp->element;
}

template<typename T>
void LinkedListStack<T>::push(T value) 
{
    Node<T>* oldHead = head_; 
    head_ = new Node<T>(value);
    head_->next = oldHead; 
    size_++;
}

template<typename T>
T LinkedListStack<T>::pop()
{
    if (head_ == NULL)
    {
        throw runtime_error("Error in pop(): LinkedListStack is empty");
    }
    T value = head_->element;
    this->removeFirst();
    return value; 
}
