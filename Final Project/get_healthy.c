#include <stdio.h>
#include "bmiformula.h"

#define TRUE 1
#define FALSE 0

int main()
{
    float bmi, h, w, lcal, gcal;  // for bmi calculations
    int planlen = 8, curweek = 1; // length of exercise plan in weeks, curweek is current week of plan
    int overweight, underweight;
    int weekprog[3][16] = {0};

    // login/signup options
    printf("======= Login/Signup =======\n"
           "(1) Login\n"
           "(2) Signup\n"); //

    // menu system here

menu:
    printf("\n==========================\n"
           "       MENU Options\n"
           "==========================\n"
           "(1) Height and Weight + BMI\n"
           "(2) Ideal BMI Comparison\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress");
    printf("\nEnter choice: ");
    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1: // height and weight + BMI
        printf("Please put your height in meters, and weight in kg.\n");
        scanf("%f %f", &h, &w);
        bmi = w / (h * h);
        if (bmi < 18.5)
            printf("Your BMI is %.1f, You are Underweight.", bmi);
        else if (bmi < 24.9)
            printf("Your BMI is %.1f, You are Healthy!", bmi);
        else if (bmi < 29.9)
            printf("Your BMI is %.1f, You are Overweight.", bmi);
        else if (bmi < 34.9)
            printf("Your BMI is %.1f, You are Obese.", bmi);
        else if (bmi < 39.9)
            printf("Your BMI is %.1f, You are Severely Obese.", bmi);
        else
            printf("Your BMI is %.1f, You are Morbiusly a Beast.", bmi);
        goto menu;
        break;
    case 2: // bmi value and classification, 7700 cal / kg
        gcal = ((18.5 - bmi) * (h * h)) * 7700;
        lcal = ((bmi - 24.9) * (h * h)) * 7700;
        if (bmi < 18.5)
        {
            printf("Your BMI is Less than Optimal; at your Current weight, you need to gain %.1f Calories.", gcal);
            underweight = TRUE;
        }
        else if (bmi > 24.9)
        {
            printf("Your BMI is More than what is Optimal; at your Current weight, you need to gain %.1f Calories.", lcal);
            overweight = TRUE;
        }
        else
        {
            printf("Your BMI is Healthy! Keep it up!"); // cant you just like display this yourself?
        }
        goto menu;
        break;
    case 3: // exercise/diet plan

        break;
    case 4: // weekly progress
        int weekchoice;

    weeklyprogress:
        printf("\n==========================\n"
               "   Weekly Progress Menu\n"
               "==========================\n"
               "(1) Enter This Week's Progress\n"
               "(2) See Weekly Progress Table\n"
               "(3) Return\n");

        printf("\nEnter choice: ");
        scanf("%d", &weekchoice);

        switch (weekchoice)
        {
        case 1:                            // updating the progress of the week
            float /*exertime,*/ foodcount; // exercise time and nugget count

            printf("\n===== Week %d Progress Report =====", curweek);
            if (/*overweight == TRUE*/ 1)
            {
                printf("\nEnter how many minutes you ran/walked/jogged/swam this week (%d) : ", curweek); // if trying to lose weight
                scanf("%f", &weekprog[0][curweek]);

                goto weeklyprogress;
            }
            else if (underweight == TRUE)
            {
                printf("\nEnter how many [foods] did you eat this week? (%d) : ", curweek);
                scanf("%f", &foodcount);
            }
            break;
        case 2: // see the weekly progress so far
            printf("\n===== Week Progress Table =====\n\n");
            printf("|                        |");

            for (int i = 1; i <= planlen; i++)
            {
                printf("|   Week %d   |", i);
            }

            printf("\n| Calories Burned/Gained |");
            for (int i = 1; i <= planlen; i++)
            {
                printf("|   %d   |", i);
            }
            curweek++;

            break;
        case 3:
            goto menu;
            break;
        }
        break;
    }
    return 0;
}