#pragma once
namespace CHAPTER4
{
struct Exercise1Output_s
{
    int Actual1;
    int Actual2;
    int Actual3;
    double Actual4;
    // Constructor
    Exercise1Output_s() :
        Actual1(0),
        Actual2(0),
        Actual3(0),
        Actual4(0.0)
    {};
};
struct Exercise7Output_s
{
    double Actual1;
    double Actual2;

    // Constructor
    Exercise7Output_s() :
        Actual1(0),
        Actual2(1)
    {};
};
struct Exercise8Output_s
{
    int Actual1;
    
    // Constructor
    Exercise8Output_s() :
        Actual1(0)
    {};
};

struct Exercise9Output_s
{
    int Actual1;
    int Actual2;

    // Constructor
    Exercise9Output_s() :
        Actual1(0),
        Actual2(0)
    {};
};
struct Exercise15Output_s
{
    int Actual1;

    // Constructor
    Exercise15Output_s() :
        Actual1(0)
    {};
};
//struct Exercise16Output_s
//{
//    string Actual1;
//
//    // Constructor
//    Exercise16Output_s() :
//        Actual1("words")
//    {};
//};
struct Exercise30Output_s
{
    double Actual1;

    // Constructor
    Exercise30Output_s() :
        Actual1(0)
    {};
};
}