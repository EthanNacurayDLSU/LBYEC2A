#include <stdio.h>
#include <string.h>
#include "bmiformula.h"

#define TRUE 1
#define FALSE 0

void weekly_prog_menu();

int main()
{
    float bmi, h, w, lcal, gcal, loptimal, goptimal; // for bmi calculations
    int planlen = 8, curweek = 1;                    // length of exercise plan in weeks, curweek is current week of plan
    int overweight, underweight;
    int weekprog[3][16] = {0}; // two dimensional array to store the weekly progress data.

    // login/signup variables
    char usernameinp[50], passwordinp[50];                             // For username and password input
    char userst[50] = "ergtfvdewerfg", passwordst[50] = "grfdsergrfd"; // For stored username and password. I put a bunch of gibberish for the initial. Not secure, I know.
    int lschoice;                                                      // For user's input in menu

    // login/signup options
    while (1)
    {
        printf("======= Login/Signup =======\n"
               "(1) Login\n"
               "(2) Signup\n");
        scanf("%d", &lschoice);
        getchar();

        // login/signup proper
        if (lschoice == 1)
        { // User Login
            printf("Enter Username: ");
            scanf("%s", usernameinp);
            printf("Enter Password: ");
            scanf("%s", passwordinp);

            if (strcmp(usernameinp, userst) == 0 && strcmp(passwordinp, passwordst) == 0)
            {
                printf("Login successful! Welcome, %s!\n", userst);
                break; // Continue to menu system if credentials are correct
            }
            else
            {
                printf("Invalid credentials. Returning to Menu. . .\n");
                continue; // Return to login menu if input credentials do not match
            }
        }
        else if (lschoice == 2)
        { // User Signup
            printf("Welcome to Get Healthy!\n Please enter your chosen Username: ");
            scanf("%s", usernameinp);
            printf("Please enter your chosen Password: ");
            scanf("%s", passwordinp);

            strcpy(userst, usernameinp);     // Copy new username to storage
            strcpy(passwordst, passwordinp); // Copy new password to storage
            printf("Signup was successful! Please login with your new account!\n");
            continue; // Go back to the login menu so user can login again
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            continue; // Return to login menu so user can try again
        }

        /* Note that signing up in this case would overwrite the previous user. I think we could use arrays to store multiple users but that's beyond my forte right now.*/
    }
    // menu system here
menu: // goto function for menu, simplifies the exit option

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
            printf("Your BMI is %.1f, You are Underweight.\n", bmi);
        else if (bmi < 24.9)
            printf("Your BMI is %.1f, You are Healthy!\n", bmi);
        else if (bmi < 29.9)
            printf("Your BMI is %.1f, You are Overweight.\n", bmi);
        else if (bmi < 34.9)
            printf("Your BMI is %.1f, You are Obese.\n", bmi);
        else if (bmi < 39.9)
            printf("Your BMI is %.1f, You are Severely Obese.\n", bmi);
        else
            printf("Your BMI is %.1f, You are Morbiusly a Beast.\n", bmi);
        goto menu;
        break;
    case 2: // bmi value and classification, 7700 cal / kg
        gcal = ((18.5 - bmi) * (h * h)) * 7700;
        lcal = ((bmi - 24.9) * (h * h)) * 7700;
        goptimal = (gcal / 7700);
        loptimal = (lcal / 7700);
        ;
        if (bmi < 18.5)
        {
            printf("Your BMI is Less than Optimal.\n");
            printf("At your Current weight of %.1f, you need to gain:\n", w);
            printf("%.1f Calories, %.1f kg.\n", gcal, goptimal);
            underweight = TRUE;
        }
        else if (bmi > 24.9)
        {
            printf("Your BMI is Higher than what is Healthy.\n");
            printf("At your Current weight of %.1f, you need to lose:\n", w);
            printf("%.1f Calories, %.1f kg.\n", lcal, loptimal);
            overweight = TRUE;
        }
        else
        {
            printf("Your BMI is Healthy! Keep it up!");
        }
        goto menu; // returns back to the menu using a goto function
        break;
    case 3: // exercise/diet plan

        break;

    case 4: // weekly progress
        weekly_prog_menu();
        break; // end of main menu switch case
    }
    return 0;
}

void weekly_prog_menu(int planlen, int curweek, int underweight, int overweight, int weekprog[][])
{
    puts("Weekly Progress was Chosen");
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
        // case 3:
        // goto menu; // option to return to the menu
        // break;
    }
}