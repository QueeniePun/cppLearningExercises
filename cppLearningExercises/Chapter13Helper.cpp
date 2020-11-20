#include "Chapter13Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

void Chapter13Helper::RunExercise1()
{
    // 13.1  Write a program to create a file named Exercise13_1.txt if it 
    //       does not exist. If it does exist, append new data to it. Write
    //       100 integers created randomly into the file using text I/O. Int
    //       are separated by a space 
    srand(time(0));
    fstream inout;
    
    inout.open("Chapter13_1.txt");

    if (inout.fail())
    {
        cout << "File does not exist" << endl;
        return;
    }

    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100; 
        inout << num << " "; 
    }

    inout.close();
}

void Chapter13Helper::RunExercise2()
{
    // 13.2 Write a program that prompts the user to enter a file name
    //      and displays the num of characters in the file 

    /*cout << "Enter a file name: ";
    string filename; 
    cin >> filename;
    
    ifstream input("Exercise13_1.txt");
    */    

    fstream input;
    input.open("Chapter13_1.txt"); 

    if (input.fail())
    {
        cout << "File does not exist" << endl;
        return; 
    }

    int numOfCharacters = 0; 
    while (!input.eof())
    {
        input.get();
        numOfCharacters++;
    }

    input.close();
    cout << numOfCharacters << endl;
}

void Chapter13Helper::RunExercise3()
{
    // 13.3 Suppose that a text file contains an unspecified
    //      number of scores. Write a program that reads the scores and displays
    //      the total and average. scores separated by blanks

    fstream inout; 
    inout.open("Chapter13_1.txt");

    if (inout.fail())
    {
        cout << "File does not exist";
        return;
    }

    double totalScores = 0.0;
    int numOfScores = 0;
    while (!inout.eof())
    {
        totalScores += inout.get();
        numOfScores++;
    }

    double average = totalScores / numOfScores; 
    cout << "Total is: " << totalScores << endl;
    cout << "Average is: " << average << endl;
}

void Chapter13Helper::RunExercise4()
{
    // 13.4 Write a program to create a file Exercise13_4 if it dne. If it does 
    //      exist, append new data to it. Write 100 integers created randomly 
    //      using text I/O. Integers are seperated by space. Read data and display
    srand(time(0));

    fstream inout;

    // create a file
    inout.open("Chapter13_4.txt", ios::out);

    // write to the file
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100; 
        inout << num << " ";
    }

    inout.close();

    // Open the file and read
    int num; 
    inout.open("Exercise13_4.txt", ios::in);
    while (!inout.eof())
    {
        inout >> num;
        cout << num << " ";
    }

    inout.close();
}

void Chapter13Helper::RunExercise5()
{
    // 13.5 Write a program to create a file named Chapter13_5.dat if it dne.
    //      If it does exist, append new data to it. Write 100 integers randomly
    //      using binary I/O

    srand(time(0));

    fstream binaryio;
    binaryio.open("Chapter13_5.dat", ios::out | ios::binary);

    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        binaryio.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
    
    binaryio.close();

    binaryio.open("Chapter13_5.dat", ios::in | ios::binary);
    int result[100];
    binaryio.read(reinterpret_cast<char*>(&result), sizeof(result));
    binaryio.close();

    for (int i = 0; i < 100; i++)
    {
        cout << result[i] << " ";
    }
}

void Chapter13Helper::RunExercise6()
{
    // 13.6 Write a program that creates five Loan objects and stores them in a file 
    //      named Chapter13_6.dat. The loan class was in Listing 9.12
}