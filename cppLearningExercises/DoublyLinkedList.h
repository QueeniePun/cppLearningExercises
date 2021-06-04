#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stdexcept>
using namespace std;

//template<typename T>
//class Node
//{
//public:
//    T element; // Element contained in the node
//    Node<T>* previous; // Pointer to the previous mode
//    Node<T>* next; // Pointer to the next node
//    
//    Node() // No-arg constructor
//    {
//        next = NULL;
//        previous = NULL;
//    }
//
//    Node(T element) // Constructor 
//    {
//        this->element = element;
//        next = NULL;
//        previous = NULL;
//    }
//};

//template<typename T>
//class Iterator : public std::iterator<std::forward_iterator_tag, T>
//{
//public:
//    Iterator(Node<T>* p)
//    {
//        current = p;
//    };
//
//    Iterator operator++()
//    {
//        current = current->next;
//        return *this;
//    }
//
//    T& operator*()
//    {
//        return current->element;
//    }
//
//    bool operator==(const Iterator<T>& iterator)
//    {
//        return current = iterator.current;
//    }
//
//    bool operator!=(const Iterator<T>& iterator)
//    {
//        return current != iterator.current;
//    }
//
//private:
//    Node<T>* current;
//};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(DoublyLinkedList<T>& list);
    ~DoublyLinkedList();
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
    void addAll(const DoublyLinkedList<T>& otherList);
    void removeAll(const DoublyLinkedList<T>& otherList);
    void retainAll(const DoublyLinkedList<T>& otherList);

    Iterator<T> begin()
    {
        return Iterator<T>(head);
    };

    Iterator<T> end()
    {
        return Iterator<T>(tail->next);
    };

private:
    Node<T>* head, * tail;
    int size;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>& list)
{
    head = tail = NULL;
    size = 0;

    Node<T>* current = list.head;
    while (current != NULL)
    {
        this->add(current->element);
        current = current->next;
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template<typename T>
void DoublyLinkedList<T>::addFirst(T element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
    {
        tail = head;
    }
}

template<typename T>
void DoublyLinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else
    {
        tail->next = new Node<T>(element);
        tail = tail->next;
    }

    size++;
}

template<typename T>
T DoublyLinkedList<T>::getFirst() const
{
    if (size == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return head->element;
    }
}

template<typename T>
T DoublyLinkedList<T>::getLast() const
{
    if (size == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return tail->element;
    }
}

template<typename T>
T DoublyLinkedList<T>::removeFirst() throw (runtime_error)
{
    if (size == 0)
    {
        throw runtime_error("No elements in the list");
    }
    else
    {
        Node<T>* temp = head;
        head = head->next;
        size--;
        if (head == NULL)
        {
            tail = NULL;
        }
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
T DoublyLinkedList<T>::removeLast() throw (runtime_error)
{
    if (size == 0)
    {
        throw runtime_error("no elements in the list");
    }
    else if (size == 1)
    {
        Node<T>* temp = head;
        head = tail = NULL;;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    }
    else
    {
        Node<T>* current = head;

        for (int i = 0; i < size - 2; i++)
        {
            current = current->next;
        }

        Node<T>* temp = tail;
        tail = current;
        tail->next = NULL;
        size--;
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
void DoublyLinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
void DoublyLinkedList<T>::add(int index, T element)
{
    if (index == 0)
    {
        addFirst(element);
    }
    else if (index >= size)
    {
        addLast(element);
    }
    else
    {
        Node<T>* current = head;

        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = new Node<T>(element);
        temp->previous = current;
        (current->next)->previous = temp;
        size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (head != NULL)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

template<typename T>
T DoublyLinkedList<T>::get(int index) const
{
    if (index < 0 || index > size - 1)
    {
        throw runtime_error("Index out of range");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->element;
}

template<typename T>
int DoublyLinkedList<T>::indexOf(T element) const
{
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
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
bool DoublyLinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template<typename T>
int DoublyLinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
T DoublyLinkedList<T>::removeAt(int index) throw (runtime_error)
{
    if (index < 0 || index >= size)
    {
        throw runtime_error("Index out of range");
    }
    else if (index == 0)
    {
        return removeFirst();
    }
    else if (index == size - 1)
    {
        return removeLast();
    }
    else
    {
        Node<T>* previous = head; 
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }
        Node<T>* current = previous->next;
        Node<T>* newCurrent = current->next; 
        previous->next = newCurrent;
        size--; 
        T element = current->element; 
        delete current; 
        return element; 

    }

    /*
    
        Node<T>* previous = head; 
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next; 
        }
        Node<T>* current = previous->next;
        Node<T>* newCurrent = current->next; 
        previous->next = newCurrent;
        size--; 
        T element = current->element;
        delete current;
        return element; 
    */
}

template<typename T>
void DoublyLinkedList<T>::remove(T element) throw (runtime_error)
{
    // Traverse through the list for the element

    Node<T>* current = head;
    for (int i = 0; i < size; i++)
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
int DoublyLinkedList<T>::lastIndexOf(T element) const
{
    // Returns the index of the last matching element in this list
    // Return -1 if the element does not exist 

    int lastIndex = -1;
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
    {
        if (current->element == element)
        {
            lastIndex = i;
        }
    }

    return lastIndex;
}

template<typename T>
bool DoublyLinkedList<T>::contains(T element) const
{

    Node<T>* current = head;
    for (int i = 0; i < size; i++)
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
T DoublyLinkedList<T>::set(int index, T element) throw (runtime_error)
{
    // Sets the element at the specified index and returns the element being replaced
    if (index < 0 || index > size - 1)
    {
        throw runtime_error("Index out of range");
    }

    T replaced = get(index);

    Node<T>* current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    current->element = element;

    return replaced;
}

template<typename T>
void DoublyLinkedList<T>::addAll(const DoublyLinkedList<T>& otherList)
{
    // Traverse through otherList and add each element to the linked List
    Node<T>* otherCurrent = otherList.head;
    for (int i = 0; i < otherList.getSize(); i++)
    {
        this->add(otherCurrent->element);
        otherCurrent = otherCurrent->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::removeAll(const DoublyLinkedList<T>& otherList)
{
    // Remove all elements in otherList from this list

    Node<T>* otherCurrent = otherList.head;
    for (int i = 0; i < otherList.getSize(); i++)
    {
        Node<T>* current = head;
        for (int j = 0; j < size; j++)
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
void DoublyLinkedList<T>::retainAll(const DoublyLinkedList<T>& otherList)
{
    // Retain the elements in this list if they are also in otherList

    // If otherList does not contain elements from list, remove the element from list
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
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