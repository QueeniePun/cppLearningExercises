#include "pch.h"
#include "../cppLearningExercises/Chapter5Helper.cpp"

TEST(Chapter5, Exercise1)
{
    // Setup supporting structures
    Chapter5Helper chapter5Helper;

    // Setup inputs
    const int INPUT = 234;

    // Setup expected outputs
    const int expected = 9;

    // Execute logic
    chapter5Helper.RunExercise2(INPUT);

    // Verify expected outputs
    EXPECT_EQ(chapter5Helper.Exercise2Output.Actual1, expected);
}
