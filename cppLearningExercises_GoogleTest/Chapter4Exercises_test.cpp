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
