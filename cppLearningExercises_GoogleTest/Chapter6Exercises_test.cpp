#include "pch.h"
#include "../cppLearningExercises/Chapter6Helper.cpp"

TEST(Chapter6, Exercise1)
{
    // Setup supporting structures
    Chapter6Helper chapter6Helper;

    // Setup inputs
    const int INPUT = 234;

    // Setup expected outputs
    const int expected = 9;

    // Execute logic
    chapter6Helper.RunExercise2(INPUT);

    // Verify expected outputs
    EXPECT_EQ(chapter6Helper.Exercise2Output.Actual1, expected);
}
