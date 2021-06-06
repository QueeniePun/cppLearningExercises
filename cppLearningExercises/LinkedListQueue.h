#pragma once
#include "LinkedList.h"
using namespace std;


template<typename T>
class LinkedListQueue : public LinkedList<T>
{
public:
    LinkedListQueue();
    ~LinkedListQueue();

    void Enqueue(T element);
    T Dequeue() throw (runtime_error);
    int GetSize() const; 
private:
    using LinkedList<T>::head_;
    using LinkedList<T>::tail_;
    using LinkedList<T>::size_;
};

template<typename T>
LinkedListQueue<T>::LinkedListQueue()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}


template<typename T>
LinkedListQueue<T>::~LinkedListQueue()
{
    this->clear();
}


template<typename T>
void LinkedListQueue<T>::Enqueue(T element)
{
    this->addLast(element);
}

template<typename T> 
T LinkedListQueue<T>::Dequeue() throw (runtime_error)
{
    return this->removeFirst();
}

template<typename T> 
int LinkedListQueue<T>::GetSize() const
{
    return this->getSize();
}