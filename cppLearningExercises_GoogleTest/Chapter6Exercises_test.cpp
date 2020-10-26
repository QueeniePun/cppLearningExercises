#include "pch.h"
#include "../cppLearningExercises/Chapter6Helper.cpp"

TEST(Chapter6, Exercise14)
{
    // Setup supporting structures
    Chapter6Helper chapter6Helper;

    // Setup inputs
    const int INPUT = 4;

    // Setup expected outputs
    const double expected = sqrt(INPUT);

    // Execute logic
    chapter6Helper.RunExercise14(INPUT);

    // Verify expected outputs
    EXPECT_NEAR(chapter6Helper.Exercise14Output.Actual1, expected, 0.01);
}
