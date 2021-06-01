#include "Chapter20Helper.h"
#include "LinkedList.h"
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
    
}

void Chapter20Helper::RunExercise3()
{
    
}

void Chapter20Helper::RunExercise4()
{
    
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
