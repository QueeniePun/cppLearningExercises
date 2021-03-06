#include "Chapter20Helper.h"
#include "Chapter12Helper.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "LinkedListStack.h"
#include "LinkedListQueue.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void Chapter20Helper::RunExercise1()
{
    // Implement remove(T element) that is omitted in listing 20.2, LinkedList.h
}

void Chapter20Helper::RunExercise2()
{
    // Implement lastIndexOf(T element)
}

void Chapter20Helper::RunExercise3()
{
    // Implement contains(T element)
}

void Chapter20Helper::RunExercise4()
{
    // Implement addAll(const LinkedList<T> &otherList)
    // Implement removeAll(const LinkedList<T> &otherlist)
    // Implement retainAll(const LinkedList<T> &otherlist)

    LinkedList<string> list1;
    list1.add("Beijing");
    list1.add("Tokyo");
    list1.add("New York");
    list1.add("London");
    list1.add("Paris");

    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }


    cout << "\n The element we want to remove is " << list1.get(1) << endl;
    list1.removeAt(1);

    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }
}

void Chapter20Helper::RunExercise5()
{
    // Write a test program that creates two linked lists, list1 and list2, with the 
    // initial values {"Beijing", "Tokyo", "New York", "London", "Paris"} and 
    // {"Beijing", "Shanghai", "Paris", "Berlin", "Rome"}, then invokes 
    // list1.addAll(list2), list1.removeAll(list2), and list1.retainAll(list2) and
    // displays the resulting new list1.  

    LinkedList<string> list1;
    list1.add("Beijing");
    list1.add("Tokyo");
    list1.add("New York");
    list1.add("London");
    list1.add("Paris");

    LinkedList<string> list2; 
    list2.add("Beijing");
    list2.add("Shanghai");
    list2.add("Paris");
    list2.add("Berlin");
    list2.add("Rome");

    LinkedList<string> list3;
    list3.add("Beijing");
    list3.add("Shanghai");
    list3.add("Paris");
    list3.add("Berlin");
    list3.add("Rome");

    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }

    list1.addAll(list2);
    cout << "\nlist1.addAll(list2):" << endl;
    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }
   
    cout << "\nlist2" << endl;
    for (int i = 0; i < list2.getSize(); i++)
    {
        cout << list2.get(i) << endl;
    }

    list1.removeAll(list2);
    cout << "\nlist1.remove(list2):" << endl;
    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }
    
    cout << "\nlist2" << endl;
    for (int i = 0; i < list2.getSize(); i++)
    {
        cout << list2.get(i) << endl;
    }
    
    cout << "\nlist3" << endl;
    for (int i = 0; i < list3.getSize(); i++)
    {
        cout << list3.get(i) << endl;
    }

    list2.retainAll(list3);
    cout << "\nlist2.retainAll(list3):" << endl;
    for (int i = 0; i < list2.getSize(); i++)
    {
        cout << list2.get(i) << endl;
    }
}

void Chapter20Helper::RunExercise6()
{
    // The LinkedList class is a singly linked list that enables one-way
    // traversal of the list. Modify the Node class to add a new field
    // previous to refer to the previous node. 
    // Simplify the implementation of add(T element, int index) and 
    // removeAt(int index) to take advantage of doubly-linked list.

    DoublyLinkedList<string> list1;
    list1.add("Beijing");
    list1.add("Tokyo");
    list1.add("New York");
    list1.add("London");
    list1.add("Paris");

    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }


    cout << "\n The element we want to remove is " << list1.get(1) << endl;
    list1.removeAt(1);

    for (int i = 0; i < list1.getSize(); i++)
    {
        cout << list1.get(i) << endl;
    }
}

void Chapter20Helper::RunExercise7()
{
    // In Listing 12.7, ImprovedStack.h, Stack is implemented using composition. 
    // Create a new stack class that extends LinkedList.

    // Reference: https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
    // Reference: https://java2blog.com/implement-stack-using-linked-list-in-java/

    // Note on template class inheritance: 
    // https://stackoverflow.com/questions/6592512/templates-parent-class-member-variables-not-visible-in-inherited-class
    /*
       The template parent of a template class is not instantiated during the compilation 
       pass that first examines the template. These names appear to be non-dependent on 
       the particular template instantiation, and therefore the definitions need to be 
       available. 
       
       You'll need to tell the compiler explicitly that the names are in fact dependent on
       the instantiation of the parent.

       One way, using this-> before all the inherited names: this->list, this->length.
       Another way, using declarations: using baseClass<elemType>::length; etc 
       (for example in the private section of the derived class).
    */

    LinkedListStack<int> list1; 
    list1.push(1);
    list1.push(2);
    list1.push(3);
    list1.push(4);
    list1.push(5);

    while (list1.getSize() > 0)
    {
        cout << list1.peek() << endl;
        list1.pop();
    }
    
}

void Chapter20Helper::RunExercise8()
{
    // In Listing 20.5 Queue.h, Queue is implemented using composition. Create 
    // a new queue class that extends LinkedList. 

    // Reference: https://www.geeksforgeeks.org/queue-linked-list-implementation/

    LinkedListQueue<int> list;
    list.Enqueue(1);
    list.Enqueue(2);
    list.Enqueue(3);
    list.Enqueue(4);
    list.Enqueue(5);

    while (list.GetSize() > 0)
    {
        cout << list.Dequeue() << endl;
    }
}