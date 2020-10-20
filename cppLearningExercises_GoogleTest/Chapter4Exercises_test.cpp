#include "pch.h"
#include "../cppLearningExercises/Chapter4Helper.cpp"

TEST(Chapter4, Exercise1)
{
    // Setup supporting structures
    Chapter4Helper chapter4Helper;

    // Setup inputs
    const int SIZE_OF_INPUTS = 4;
    int inputs[SIZE_OF_INPUTS] = { 1, 2, -1, 3 };

    // Setup expected outputs
    const int SIZE_OF_OUTPUTS = 4;
    double expected[SIZE_OF_OUTPUTS] = { 3, 1, 5, 1.25 };

    // Execute logic
    chapter4Helper.RunExercise1(inputs, SIZE_OF_INPUTS);

    // Verify expected outputs
    EXPECT_NEAR(chapter4Helper.Exercise1Output.Actual1, expected[0], 0.1);
    EXPECT_NEAR(chapter4Helper.Exercise1Output.Actual2, expected[1], 0.1);
    EXPECT_NEAR(chapter4Helper.Exercise1Output.Actual3, expected[2], 0.1);
    EXPECT_NEAR(chapter4Helper.Exercise1Output.Actual4, expected[3], 0.01);

}

TEST(Chapter4, Exercise7)
{
    // Setup supporting structures
    Chapter4Helper chapter4Helper;

    // Setup inputs
    double initialTuition = 10000;
    double years = 10;

    // Setup expected outputs
    double expected_1 = 16288.95;
    double expected_2 = 70207.394;

    // Execute logic 
    chapter4Helper.RunExercise7(initialTuition, years);

    // Verify expected outputs
    EXPECT_NEAR(chapter4Helper.Exercise7Output.Actual1, expected_1, 0.1);
    EXPECT_NEAR(chapter4Helper.Exercise7Output.Actual2, expected_2, 0.1);

}

TEST(Chapter4, Exercise8)
{
    // Setup supporting structures
    Chapter4Helper chapter4Helper;

    // Setup inputs
    const int NUM_STUDENTS = 10;
    int studentScores[NUM_STUDENTS] = { 100, 89, 44, 56, 70, 68, 30, 87, 0 };

    // Setup expected outputs
    int expected_1 = 100;

    // Execute logic
    chapter4Helper.RunExercise8(NUM_STUDENTS, studentScores);

    // Verify expected outputs
    EXPECT_EQ(chapter4Helper.Exercise8Output.Actual1, expected_1);
}

TEST(Chapter4, Exercise9)
{
    // Setup supporting structures
    Chapter4Helper chapter4Helper;

    // Setup inputs
    const int NUM_STUDENTS = 10;
    int studentScores[NUM_STUDENTS] = { 100, 3, 23, 24, 70, 48, 88, 98, 54, 77 };

    // Setup expecteed outputs
    int expected_1 = 100;
    int expected_2 = 98;

    // Execute logic
    chapter4Helper.RunExercise9(NUM_STUDENTS, studentScores);

    // Verify expected ouputs
    EXPECT_EQ(chapter4Helper.Exercise9Output.Actual1, expected_1);
    EXPECT_EQ(chapter4Helper.Exercise9Output.Actual2, expected_2);
}

TEST(Chapter4, Exercise15)
{
    // Setup supporting structures
    Chapter4Helper chapter4Helper;

    // Setup inputs
    int n1 = -680;
    int n2 = 32;

    // Setup expected outputs
    int expected_1 = 8;

    // Execute logic 
    chapter4Helper.RunExercise15(n1, n2);

    // Verify expected outputs
    EXPECT_EQ(chapter4Helper.Exercise15Output.Actual1, expected_1);
}

//TEST(Chapter4, Exercise16)
//{
//    // Setup
//    Chapter4Helper chapter4Helper;
//
//    // Inputs
//    int num = 120;
//
//    // Expected Outputs
//    string expected_1 = "2 2 2 3 5 ";
//
//    // Execute logic
//    chapter4Helper.RunExercise16(num);
//
//    // Verify expected outputs 
//    EXPECT_EQ(chapter4Helper.Exercise16Output.Actual1, expected_1);
//}