#include <stdio.h>

#define TRUE 1
#define FALSE 0

void checkPlan(int underweight, int overweight, int *exdiechoice)
{
    if (underweight == TRUE && overweight == FALSE)
    {
        printf("You are underweight. Loading diet plan. . .\n");
        *exdiechoice = 2; // Loads Diet Plan
    }
    else if (underweight == FALSE && overweight == TRUE)
    {
        printf("You are overweight. Loading exercise plan. . .\n");
        *exdiechoice = 1; // Loads Exercise Plan
    }
    else if (underweight == FALSE && overweight == FALSE)
    {
        printf("You have not taken the BMI test. Please take the BMI test and return to this menu.");
        *exdiechoice = 3; // Boots user back to menu, like the skipper he is
    }
    else
    {
        printf("Something has gone terribly wrong.");
        *exdiechoice = 3; // Boots user back to menu, because we screwed up
    }
}

void calcuExer(int *exmchoice, float lcal, int planlen, float *hrsneed, float *minsneed, float *loseweek, char **thatstring) // Calculations for Exercise Needed, pointers modify value from here to main
{
    float calBurn[] = {350, 450, 600, 500};                             // float array of how many calories burned per hour, ordered by menu option
    char *activities[] = {"walking", "jogging", "running", "swimming"}; // changed these to all lower case, makes it easier to integrate into sentences later
    if (*exmchoice < 1 || *exmchoice > 4)
    {
        printf("Invalid option. Please try again.\n"); // Invalid option
        return;
    }

    *loseweek = lcal / planlen;
    *hrsneed = lcal / (planlen * calBurn[*exmchoice - 1]);
    *minsneed = (*hrsneed) * 60;
    *thatstring = activities[*exmchoice - 1];

    printf("You need to lose %.1f calories, which means you need to aim to lose around %.1f calories per week.\n", lcal, lcal / planlen);
    printf("Consider aiming to do %s for at least %.1f minutes every week.\n", *thatstring, *minsneed); // changed it from this week to every week

    // printf("DEBUG INSIDE CALCUEXER FUNCTION: Loseweek=%.2f, HrsNeed=%.2f, MinsNeed=%.2f\n", *loseweek, *hrsneed, *minsneed);
}

void calcuDiet(int *dtchoice, float gcal, int planlen, float *servingsweek, float *gainweek, char **thatstring) // Calculations for Diet, pointers modify value from here to main
{
    float calLose[] = {302, 132, 130, 34};                           // Calories per serving of food
    char *foods[] = {"chicken Nuggets", "tuna", "rice", "broccoli"}; // changed these to all lower case, makes it easier to integrate into sentences later
    if (*dtchoice < 1 || *dtchoice > 4)
    {
        printf("Invalid option. Please try again.\n"); // float array of how many calories burned per hour, ordered by menu option
        return;
    }

    *gainweek = gcal / planlen;
    *servingsweek = (*gainweek) / calLose[*dtchoice - 1]; //
    *thatstring = foods[*dtchoice - 1];

    printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.\n", gcal, *gainweek);
    printf("Consider aiming to eat at least %.1f servings of %s every week.\n", *servingsweek, *thatstring); // changed it from this week to every week
}

void exercisePlan(float bmi, float lcal, int planlen, int *exmchoice, float *hrsneed, float *minsneed, float *loseweek, char **thatstring) // Exercise Plan Menu
{
    if (bmi < 18.5)
    {
        printf("You are already underweight! Please reconsider doing an exercise plan.\n");
        return;
    }

    printf("\n===============================\n"
           "      Choose Your Activity\n"
           "===============================\n"
           "(1) Walking\n"
           "(2) Jogging\n"
           "(3) Running\n"
           "(4) Swimming\n");

    printf("\nEnter choice: ");
    scanf("%d", exmchoice);

    calcuExer(exmchoice, lcal, planlen, hrsneed, minsneed, loseweek, thatstring); // Function Call for Exercise Calculations
}

void dietPlan(float bmi, float gcal, int planlen, int *dtchoice, float *servingsweek, float *gainweek, char **thatstring) // Diet Plan Menu
{
    if (bmi > 24.9)
    {
        printf("You are already overweight! Please reconsider doing a diet plan.\n");
        return;
    }

    printf("\n===============================\n"
           "      Choose Your Craving\n"
           "===============================\n"
           "(1) Chicken Nuggets\n"
           "(2) Tuna\n"
           "(3) Rice\n"
           "(4) Broccoli\n");

    printf("\nEnter choice: ");
    scanf("%d", dtchoice);

    calcuDiet(dtchoice, gcal, planlen, servingsweek, gainweek, thatstring); // Function Call for Diet Calculations
}
