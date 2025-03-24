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

void calcuExer(int exmchoice, float lcal, int planlen) // Calculations for Exercise Needed
{
    float calBurn[] = {350, 450, 600, 500}; // float array of how many calories burned per hour, ordered by menu option
    if (exmchoice < 1 || exmchoice > 4)
    {
        printf("Invalid option. Please try again.\n"); // Invalid option
        return;
    }

    float hrsneed = lcal / (planlen * calBurn[exmchoice - 1]);
    float minsneed = hrsneed * 60;
    float loseweek = lcal / planlen;

    printf("You need to lose %.1f calories, which means you need to aim to lose around %.1f calories per week.\n", lcal, loseweek);
    printf("Consider aiming to do your chosen activity for at least %.1f minutes this week.\n", minsneed);
}

void calcuDiet(int dtchoice, float gcal, int planlen) // Calculations for Diet
{
    float calLose[] = {302, 132, 130, 34}; // Calories per serving of food
    if (dtchoice < 1 || dtchoice > 4)
    {
        printf("Invalid option. Please try again.\n"); // float array of how many calories burned per hour, ordered by menu option
        return;
    }

    float servingsweek = (gcal / planlen) / calLose[dtchoice - 1]; //
    float gainweek = gcal / planlen;

    printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.\n", gcal, gainweek);
    printf("Consider aiming to eat at least %.1f servings of this food this week.\n", servingsweek);
}

void exercisePlan(float bmi, float lcal, int planlen) // Exercise Plan Menu
{
    if (bmi < 18.5)
    {
        printf("You are already underweight! Please reconsider doing an exercise plan.\n");
        printf("Returning to the menu...\n");
        return;
    }

    printf("\n===============================\n"
           "      Choose Your Activity\n"
           "===============================\n"
           "(1) Walking\n"
           "(2) Jogging\n"
           "(3) Running\n"
           "(4) Swimming\n");

    int exmchoice;
    printf("\nEnter choice: ");
    scanf("%d", &exmchoice);

    calcuExer(exmchoice, lcal, planlen); // Function Call for Exercise Calculations
}

void dietPlan(float bmi, float gcal, int planlen) // Diet Plan Menu
{
    if (bmi > 24.9)
    {
        printf("You are already overweight! Please reconsider doing a diet plan.\n");
        printf("Returning to the menu...\n");
        return;
    }

    printf("\n===============================\n"
           "      Choose Your Craving\n"
           "===============================\n"
           "(1) Chicken Nuggets\n"
           "(2) Tuna\n"
           "(3) Rice\n"
           "(4) Broccoli\n");

    int dtchoice;
    printf("\nEnter choice: ");
    scanf("%d", &dtchoice);

    calcuDiet(dtchoice, gcal, planlen); // Function Call for Diet Calculations
}
