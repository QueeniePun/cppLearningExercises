#include "pch.h"
#include "../cppLearningExercises/Chapter7Helper.cpp"

TEST(Chapter7, Exercise1)
{
    // Setup supporting structures
    Chapter7Helper chapter7Helper;

    // Setup inputs
    const int ARRAY_SIZE = 10;
    double arr[ARRAY_SIZE] = { 1, 2.7, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Setup expected outputs
    const double expectedAverage = 5.57;
    const int expectedNumValues = 5;

    // Execute logic
    chapter7Helper.RunExercise1(arr, ARRAY_SIZE);

    // Verify expected outputs
    EXPECT_EQ(chapter7Helper.Exercise1Output.Actual1, expectedAverage);
    EXPECT_EQ(chapter7Helper.Exercise1Output.Actual2, expectedNumValues);
}

TEST(Chapter7, Exercise13)
{
    Chapter7Helper chapter7Helper;

    const double COMMISSION_SOUGHT = 30000; 
    const double EXPECTED = 208333.33;

    chapter7Helper.RunExercise13(COMMISSION_SOUGHT);

    EXPECT_NEAR(chapter7Helper.Exercise13Output.Actual1, EXPECTED, 0.1);
}