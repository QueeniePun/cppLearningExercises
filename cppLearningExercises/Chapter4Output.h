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
struct Exercise2Output_s
{
    int Actual1;
    int Actual2;

    // Constructor
    Exercise2Output_s() :
        Actual1(0),
        Actual2(1)
    {};
};
}