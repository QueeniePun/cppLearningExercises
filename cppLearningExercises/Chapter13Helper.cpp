#include "Chapter13Helper.h"
#include "Chapter10Helper.h"
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

    // cout << "Enter a file name: ";
    string filename = "C:\\Users\\Queenie\\source\\repos\\cppLearningExercises\\cppLearningExercises\\Chapter13_1.txt";
    // cin >> filename;
    
    ifstream input(filename.c_str());
       
    /*fstream input;
    input.open("Chapter13_1.txt"); */

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
    
    fstream inout; 
    inout.open("Chapter13_6.dat", ios::out);

    Chapter10Helper::Loan loan1;
    Chapter10Helper::Loan loan2;
    Chapter10Helper::Loan loan3;
    Chapter10Helper::Loan loan4;
    Chapter10Helper::Loan loan5;

    inout.write(reinterpret_cast<char*>
        (&loan1), sizeof(Chapter10Helper::Loan));
    inout.write(reinterpret_cast<char*>
        (&loan2), sizeof(Chapter10Helper::Loan));
    inout.write(reinterpret_cast<char*>
        (&loan3), sizeof(Chapter10Helper::Loan));
    inout.write(reinterpret_cast<char*>
        (&loan4), sizeof(Chapter10Helper::Loan));
    inout.write(reinterpret_cast<char*>
        (&loan5), sizeof(Chapter10Helper::Loan));

    inout.close();

}

void Chapter13Helper::RunExercise7()
{
    // 13.7 Supposed the Chapter13_6.dat file has been created. Write a program
    //      that reads the Loan objects from the file and computes a total of 
    //      the loan amount. Suppose you don't know how many loans are in the file.
    // Reference: https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons

    fstream out; 
    out.open("CHapter13_6.dat", ios::in | ios::binary);
    
    double sumLoan = 0.0;
    Chapter10Helper::Loan loanNew;

    // this prevents it from reading an extra iteration, by checking for whitespace
    while (!(out>>std::ws).eof())
    {       
        out.read(reinterpret_cast<char*>(&loanNew), sizeof(Chapter10Helper::Loan));
        sumLoan += loanNew.getLoan();
 
    }

    cout << "Total loan amount: " << sumLoan;

    out.close();
}

void Chapter13Helper::RunExercise8()
{
    // 13.8 Revise Listing 13.6 using binary I/O

    string inputFilename;
    string outputFilename;

    ifstream input(inputFilename.c_str(), ios::binary);
    ofstream output(outputFilename.c_str(), ios::binary);

    if (input.fail())
    {
        cout << "Input file does not exist";
        return;
    }

    char ch[1024];
    while (!input.eof())
    {
        input.read(ch, 1024);
        output.write(ch, input.gcount()); // gcount 
    }

    input.close();
    output.close();

    cout << "\n Copy done";
}

void Chapter13Helper::RunExercise9()
{
    // 13.9 Write a utility program that splits a large file into smaller ones. 
    //      Your program should prompt the user to enter a source file and a num 
    //      of bytes in each smaller file.

    char * buffer1;
    char * buffer2;
     long size;
    long splitSize; 
    fstream input("Chapter13_1.txt");
    fstream output1("new.txt");
    fstream output2("new2.txt");
    
    if (input.fail())
    {
        cout << "File does not exist";
        return; 
    }

    // get size of the file to split
    input.seekg(0, ios::end);
    size = input.tellg();
    input.seekg(0);
    splitSize = static_cast<int>(floor(size / 2));

    buffer1 = new char[splitSize];
    buffer2 = new char[splitSize];

    input.read(buffer1, splitSize);
    input.read(buffer2, splitSize);
    
    output1.write(buffer1, splitSize);
    output2.write(buffer1, splitSize);

    // delete dynamically allocated memory
    delete[] buffer1;
    delete[] buffer2;

    output1.close();
    input.close();
    output2.close();

}

void Chapter13Helper::RunExercise10()
{
    // 13.10 Write a utility program that combines files into a new file 
    
    long size = 0;
    fstream input1("Chapter13_1.txt");
    fstream input2("Chapter13_4.txt");
    fstream output("test.txt");

    // get size of new combined file
    input1.seekg(0, ios::end);
    size += input1.tellg();
    input1.seekg(0);
    
    input2.seekg(0, ios::end);
    size += input2.tellg();
    input2.seekg(0);

    // write to output file
    int num;
    while (!input1.eof())
    {
        input1.read(reinterpret_cast<char*>(&num), sizeof(num));
        output.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    while (!input2.eof())
    {
        input2.read(reinterpret_cast<char*>(&num), sizeof(num));
        output.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    input1.close();
    input2.close();
    output.close();
}

void Chapter13Helper::RunExercise11()
{
    // 13.11 Encode the file by adding 5 to every byte in it. Write a program
    //       that prompts the user to enter an input filename and output filename 
    //       and should save the encrypyed version to the output file 

    fstream input("Chapter13_1.txt");
    fstream output("test1.txt");

    int num;
    while (!input.eof())
    {
        input.read(reinterpret_cast<char*>(&num), sizeof(num));
        num += 5;
        output.write(reinterpret_cast<char*>(&num), sizeof(num));

    }

    input.close();
    output.close();
}

void Chapter13Helper::RunExercise12()
{
    // 13.12 Supposed a file is encrypted like in 13.11. Write a program to decode it

    fstream input("test1.txt");
    fstream output("test2.txt");

    int num;
    while (!input.eof())
    {
        input.read(reinterpret_cast<char*>(&num), sizeof(num));
        num -= 5; 
        output.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    input.close();
    output.close();
}

void Chapter13Helper::RunExercise13()
{
    // 13.13 Rewrite Exercise 10.23. 

    // create a text file that contains words, separated by spaces such that 
    // the delimiter is a space. 
    // read the words from the file and store them in a vector 

     // create vector
    vector<string> words;

    string word; 
    fstream input("Chapter13_13.txt");
    while (!input.eof())
    {
        getline(input, word);
        words.push_back(word);
    }
   
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}

void Chapter13Helper::RunExercise14()
{
    // 13.14 Keep track how many times program is executed, use binary

    fstream inout; 
    inout.open("Chapter13_14.dat", ios::in | ios::out | ios::binary);

    int num = 0; 
    inout.read(reinterpret_cast<char*>(&num), sizeof(num));
    num++;
    inout.write(reinterpret_cast<char*>(&num), sizeof(num));

    inout.close();
}