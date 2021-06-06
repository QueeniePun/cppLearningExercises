#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
using namespace std;

template<typename T>
class Node
{
public:
    T element; // Element contained in the node
    Node<T>* previous; // Pointer to the previous mode
    Node<T>* next; // Pointer to the next node

    Node() // No-arg constructor
    {
        next = NULL;
        previous = NULL;
    }

    Node(T element) // Constructor 
    {
        this->element = element;
        next = NULL;
        previous = NULL;
    }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    Iterator(Node<T>* p)
    {
        current = p;
    };

    Iterator operator++()
    {
        current = current->next; 
        return *this;
    }

    T& operator*()
    {
        return current->element;
    }

    bool operator==(const Iterator<T>& iterator)
    {
        return current = iterator.current;
    }

    bool operator!=(const Iterator<T>& iterator)
    {
        return current != iterator.current;
    }

private:
    Node<T>* current;
};

template<typename T> 
class LinkedList
{
public:
    // Constructors
    LinkedList();
    LinkedList(LinkedList<T>& list);

    // Destructor 
    ~LinkedList();

    // Getters

    // Setters

    // Methods
    void addFirst(T element);
    void addLast(T element);
    T getFirst() const;
    T getLast() const;
    T removeFirst() throw(runtime_error);
    T removeLast();
    void add(T element);
    void add(int index, T element);
    void clear();
    bool contains(T element) const;
    T get(int index) const; 
    int indexOf(T element) const;
    bool isEmpty() const;
    int lastIndexOf(T element) const; 
    void remove(T element); 
    int getSize() const;
    T removeAt(int index);
    T set(int index, T element); 
    void addAll(const LinkedList<T> &otherList);
    void removeAll(const LinkedList<T>& otherList);
    void retainAll(const LinkedList<T>& otherList);

    Iterator<T> begin()
    {
        return Iterator<T>(head_);
    };

    Iterator<T> end()
    {
        return Iterator<T>(tail_->next);
    };

protected:
    Node<T>* head_;
    Node<T>* tail_;
    int size_; 
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head_ = tail_ = NULL;
    size_ = 0; 
}

template<typename T> 
LinkedList<T>::LinkedList(LinkedList<T>& list)
{
    head_ = tail_ = NULL;
    size_ = 0;

    Node<T>* current = list.head_;
    while (current != NULL)
    {
        this->add(current->element);
        current = current->next; 
    }
}

template<typename T> 
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head_;
    head_ = newNode;
    size_++;

    if (tail_ == NULL)
    {
        tail_ = head_; 
    }
}

template<typename T> 
void LinkedList<T>::addLast(T element)
{
    if (tail_ == NULL)
    {
        head_ = tail_ = new Node<T>(element);
    }
    else
    {
        tail_->next = new Node<T>(element);
        tail_ = tail_->next; 
    }

    size_++;
}

template<typename T> 
T LinkedList<T>::getFirst() const
{
    if (size_ == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return head_->element;
    }
}

template<typename T>
T LinkedList<T>::getLast() const
{
    if (size_ == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return tail_->element;
    }
}

template<typename T> 
T LinkedList<T>::removeFirst() throw (runtime_error)
{
    if (size_ == 0)
    {
        throw runtime_error("No elements in the list");
    }
    else
    {
        Node<T>* temp = head_; 
        head_ = head_->next;
        size_--;
        if (head_ == NULL)
        {
            tail_ = NULL;
        }
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T> 
T LinkedList<T>::removeLast() throw (runtime_error)
{
    if (size_ == 0)
    {
        throw runtime_error("no elements in the list");
    }
    else if( size_ == 1)
    {
        Node<T>* temp = head_; 
        head_ = tail_ = NULL;;
        size_ = 0; 
        T element = temp->element;
        delete temp;
        return element; 
    }
    else
    {
        Node<T>* current = head_; 

        for (int i = 0; i < size_ - 2; i++)
        {
            current = current->next; 
        }

        Node<T>* temp = tail_;
        tail_ = current; 
        tail_->next = NULL;
        size_--; 
        T element = temp->element;
        delete temp;
        return element; 
    }
}

template<typename T>
void LinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T> 
void LinkedList<T>::add(int index, T element)
{
    if (index == 0)
    {
        addFirst(element);
    }
    else if (index >= size_)
    {
        addLast(element);
    }
    else
    {
        Node<T>* current = head_; 

        for (int i = 1; i < index; i++)
        {
            current = current->next; 
        }

        Node<T>* temp = current->next; 
        current->next = new Node<T>(element);
        (current->next)->next = temp; 
        size_++;
    }
}

template<typename T> 
void LinkedList<T>::clear()
{
    while (head_ != NULL)
    {
        Node<T> *temp = head_; 
        head_ = head_->next; 
        delete temp;
    }
    tail_ = NULL;
}

template<typename T> 
T LinkedList<T>::get(int index) const
{
    if (index < 0 || index > size_ - 1)
    {
        throw runtime_error("Index out of range");
    }

    Node<T>* current = head_; 
    for (int i = 0; i < index; i++)
    {
        current = current->next; 
    }

    return current->element; 
}

template<typename T> 
int LinkedList<T>::indexOf(T element) const
{
    Node<T>* current = head_; 
    for (int i = 0; i < size_; i++)
    {
        if (current->element == element)
        {
            return i;
        }
        current = current->next; 
    }
    return -1; 
}

template<typename T> 
bool LinkedList<T>::isEmpty() const
{
    return head_ == NULL;
}

template<typename T> 
int LinkedList<T>::getSize() const
{
    return size_; 
}

template<typename T> 
T LinkedList<T>::removeAt(int index) 
{
    // Removes the element at the specified index and returns the 
    // removed element 

    if (index < 0 || index >= size_)
    {
        throw runtime_error("Index out of range");
    }
    else if (index == 0)
    {
        return removeFirst();
    }
    else if (index == size_ - 1)
    {
        return removeLast();
    }
    else
    {
        Node<T>* previous = head_; 
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next; 
        }
        Node<T>* current = previous->next;
        Node<T>* newCurrent = current->next; 
        previous->next = newCurrent;
        size_--; 
        T element = current->element;
        delete current;
        return element; 
    }
}

template<typename T>
void LinkedList<T>::remove(T element) 
{  
    // Traverse through the list for the element

    Node<T>* current = head_; 
    for (int i = 0; i < size_; i++)
    {
        if (current->element == element)
        {
            current = current->next; 
            removeAt(i);
            i--;
        }
        else
        {
            current = current->next;
        }
    }
}
template<typename T> 
int LinkedList<T>::lastIndexOf(T element) const
{
    // Returns the index of the last matching element in this list
    // Return -1 if the element does not exist 

    int lastIndex = -1; 
    Node<T>* current = head_; 
    for (int i = 0; i < size_; i++)
    {
        if (current->element == element)
        {
            lastIndex = i;
        }
    }

    return lastIndex;
}

template<typename T>
bool LinkedList<T>::contains(T element) const
{
 
    Node<T>* current = head_;
    for (int i = 0; i < size_; i++)
    {
        if (current->element == element)
        {
            return true; 
        }
        current = current->next; 
    }

    return false; 
}

template<typename T> 
T LinkedList<T>::set(int index, T element)
{
    // Sets the element at the specified index and returns the element being replaced
    if (index < 0 || index > size_ - 1)
    {
        throw runtime_error("Index out of range");
    }

    T replaced = get(index);
    
    Node<T>* current = head_; 
    for (int i = 0; i < index-1; i++)
    {
        current = current->next; 
    }
    current->element = element;

    return replaced; 
}

template<typename T>
void LinkedList<T>::addAll(const LinkedList<T>& otherList)
{
    // Traverse through otherList and add each element to the linked List
    Node<T>* otherCurrent = otherList.head_; 
    for (int i = 0; i < otherList.getSize(); i++)
    {
        this->add(otherCurrent->element);
        otherCurrent = otherCurrent->next;
    }
}

template<typename T> 
void LinkedList<T>::removeAll(const LinkedList<T>& otherList)
{
    // Remove all elements in otherList from this list

    Node<T>* otherCurrent = otherList.head_; 
    for (int i = 0; i < otherList.getSize(); i++)
    {
        Node<T>* current = head_; 
        for (int j = 0; j < size_; j++)
        {
            if (otherCurrent->element == current->element)
            {
                current = current->next; 
                
                // If the element is in this list, remove the element  
                remove(otherCurrent->element);
            }
            else
            {
                current = current->next;
            }
        }
        otherCurrent = otherCurrent->next; 
    }

}

template<typename T> 
void LinkedList<T>::retainAll(const LinkedList<T>& otherList)
{
    // Retain the elements in this list if they are also in otherList

    // If otherList does not contain elements from list, remove the element from list
    Node<T>* current = head_; 
    for (int i = 0; i < size_; i++)
    {
        if (!(otherList.contains(current->element)))
        {
            string ele = current->element;
            current = current->next;
            remove(ele);
            i--;
        }
        else
        {
            current = current->next;
        }
    }
}



#endif