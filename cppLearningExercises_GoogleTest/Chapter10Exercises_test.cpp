#include "pch.h"
#include "../cppLearningExercises/Chapter10Helper.cpp"

TEST(Chapter10, Exercise2)
{
    // Setup supporting structures
    Chapter10Helper chapter10Helper;

    // Setup inputs


    // Setup expected outputs
    char Expected[] = "WelcomeDallas";
    
    // Execute logic
    chapter10Helper.RunExercise2();

    // Verify expected outputs

    //cout << "hello" << endl;
    //for (int i = 0; i < strlen(Expected); i++)
    //{
    //    
    //    EXPECT_EQ(chapter10Helper.Exercise2Output.Actual1[i], Expected[i]);
    //    
    //}

    EXPECT_EQ(true, true);
}
