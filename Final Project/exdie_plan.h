#include <stdio.h>

void displayExdieMenu()
{
    printf("\n==========================\n"
           "      PLAN MENU Options\n"
           "==========================\n"
           "(1) Exercise Plan\n"
           "(2) Diet Plan\n");
}

void displayExerMenu()
{
    printf("\n==========================\n"
           "      PLAN MENU Options\n"
           "==========================\n"
           "(1) Exercise Plan\n"
           "(2) Diet Plan\n");
}

void displayDietMenu()
{
    printf("\n===============================\n"
           "      Choose Your Craving\n"
           "===============================\n"
           "(1) Chicken Nuggets\n"
           "(2) Tuna\n"
           "(3) Rice\n"
           "(4) Broccoli\n");
}

void walkin(float loseweek, )
{
    hourwalk = 350;
    hewalks = lcal / (planlen * hourwalk); // Calculates hours needed to walk per week
    minwalks = (hewalks * 60);
    printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek); 
    printf("Consider aiming to walk for at least %.1f minutes this week", minwalks);
}