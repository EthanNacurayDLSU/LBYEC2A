#include <stdio.h>
#include <string.h>
#include "bmiformula.h"
#include "weekly_prog.h"
// #include "exdie_plan.h"

#define TRUE 1
#define FALSE 0

void main_menu();

int main()
{
    float bmi, h, w, lcal, gcal, loptimal, goptimal; // for bmi calculations

    int overweight, underweight;
    int weekprog[3][16] = {0};    // two dimensional array to store the weekly progress data.
    int planlen = 8, curweek = 1; // length of exercise plan in weeks, curweek is current week of plan

    // login/signup variables
    char usernameinp[50], passwordinp[50];         // For username and password input
    char userst[50] = "/n", passwordst[50] = "/n"; // For stored username and password.
    int lschoice;                                  // For user's input in menu

    // ASCII Text LOGO
    puts("\n\n\n");
    puts("  ____      _     _   _            _ _   _           _ ");
    puts(" / ___| ___| |_  | | | | ___  __ _| | |_| |__  _   _| |");
    puts("| |  _ / _ \\ __| | |_| |/ _ \\/ _` | | __| '_ \\| | | | |");
    puts("| |_| |  __/ |_  |  _  |  __/ (_| | | |_| | | | |_| |_|");
    puts(" \\____|\\___|\\__| |_| |_|\\___|\\__,_|_|\\__|_| |_|\\__, (_)");
    puts("                                               |___/   ");

    // login/signup options
    while (1)
    {
        printf("======= Login/Signup =======\n");
        if (strcmp(userst, "/n") == 0 && strcmp(passwordst, "/n") == 0)
        {
            printf("No account found! Please sign up first.\n");
            lschoice = 2; // Forces user to signup menu if no account found
        }
        else
        {
            printf(
                "(1) Login\n"
                "(2) Signup\n");
            scanf("%d", &lschoice);
            getchar();
        }

        // login/signup proper
        if (lschoice == 1)
        { // User Login
            printf("Enter Username: ");
            fgets(usernameinp, sizeof(usernameinp), stdin);
            usernameinp[strcspn(usernameinp, "\n")] = 0;

            printf("Enter Password: ");
            fgets(passwordinp, sizeof(passwordinp), stdin);
            passwordinp[strcspn(passwordinp, "\n")] = 0;

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
            printf("Welcome to Get Healthy!\nPlease enter your chosen Username: ");

            fgets(usernameinp, sizeof(usernameinp), stdin);
            usernameinp[strcspn(usernameinp, "\n")] = 0;

            printf("Please enter your chosen Password: ");
            fgets(passwordinp, sizeof(passwordinp), stdin);
            passwordinp[strcspn(passwordinp, "\n")] = 0;

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
    }

    // menu system here

    int menu = 0;
menu:

    main_menu(&menu);

    switch (menu)
    {
    case 1: // height and weight + BMI
        heightweight(&h, &w, &bmi);

        getchar();
        goto menu;
        break;
    case 2: // bmi value and classification, 7700 cal / kg

        bmiclass(&h, &w, &bmi, &gcal, &lcal, &goptimal, &loptimal, &underweight, &overweight);

        getchar();
        goto menu;
        break;
    case 3: // exercise/diet plan
        /*
        if (!(bmi < 18.5) && !(bmi > 24.9))
            {
                printf("Since you're already healthy, just maintain your current lifestyle!"); // Basically if user is already healthy, then no exercise or diet plan is needed.
                break;
            }

            else
            {
                displayExdieMenu(); // Function Call [exdie_plan] : Prints out Initial Plan Menu
                int xdplan;
                printf("\nEnter choice: ");
                scanf("%d", &xdplan);

                switch (xdplan)
                {
                case 1:             // Exercise Plan
                    if (bmi < 18.5) // Prevents exercise plan if underweight
                    {
                        printf("You are already underweight! Please reconsider doing an exercise plan.");
                    }
                    else
                    {
                        displayExerMenu(); // Function Call [exdie_plan] : Prints out Exercise Plan Menu
                        int actplan;
                        printf("\nEnter choice: ");
                        scanf("%d", &actplan);

                        float hewalks, hejogs, heruns, heswims, minwalks, minjogs, minruns, minswims, hourwalk = 350, hourjog = 450, hourrun = 600, hourswim = 500, // Variables for calculations.
                            loseweek = lcal / planlen;                                                                                                              // Calculates hours needed to lose per week

                        switch (actplan)
                        {
                        case 1:
                            hewalks = lcal / (planlen * hourwalk);                                                                                 // Calculates hours needed to walk per week
                            minwalks = (hewalks * 60);                                                                                             // Converts hours to minutes
                            printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek); // Make function call for this
                            printf("Consider aiming to walk for at least %.1f minutes this week", minwalks);
                            break;
                        case 2:
                            hejogs = lcal / (planlen * hourjog);
                            minjogs = (hejogs * 60);
                            printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek);
                            printf("Consider aiming to jog for at least %.1f minutes this week", minjogs);
                            break;
                        case 3:
                            heruns = lcal / (planlen * hourrun);
                            minruns = (heruns * 60);
                            printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek);
                            printf("Consider aiming to run for at least %.1f minutes this week", minruns);
                            break;
                        case 4:
                            heswims = lcal / (planlen * hourswim);
                            minruns = (heswims * 60);
                            printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek);
                            printf("Consider aiming to swim for at least %.1f minutes this week", minswims);
                            break;
                        default:
                            printf("Invalid option. Please try again.\n");
                            break;
                        }
                    }
                    break;
                case 2:             // Diet Plan
                    if (bmi > 24.9) // Prevents diet plan if overweight
                    {
                        printf("You are already overweight! Please reconsider doing a diet plan.");
                    }
                    else
                    {
                        displayDietMenu(); // Function Call [exdie_plan] : Prints out Diet Plan Menu
                        int dtplan;
                        printf("\nEnter choice: ");
                        scanf("%d", &dtplan);

                        float onenugget = 302, onefish = 132, onerice = 130, onebroccoli = 34, servingsperweek;
                        float gainweek = gcal / planlen;

                        switch (dtplan)
                        {
                        case 1:
                            servingsperweek = gainweek / onenugget;
                            printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.", gcal, gainweek); // Make function call for this
                            printf("Consider aiming to eat at least %.1f servings of nuggets this week", servingsperweek);
                            break;
                        case 2:
                            servingsperweek = gainweek / onefish;
                            printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.", gcal, gainweek);
                            printf("Consider aiming to eat at least %.1f servings of tuna this week", servingsperweek);
                            break;
                        case 3:
                            servingsperweek = gainweek / onerice;
                            printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.", gcal, gainweek);
                            printf("Consider aiming to eat at least %.1f servings of rice this week", servingsperweek);
                            break;
                        case 4:
                            servingsperweek = gainweek / onebroccoli;
                            printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.", gcal, gainweek);
                            printf("Consider aiming to eat at least %.1f servings of broccoli this week", servingsperweek);
                            break;
                        default:
                            printf("Invalid option. Please try again.\n");
                            break;
                        }
                    }

                    break;
                default:
                    printf("Invalid option. Please try again.\n"); /* Don't know how to make this loop back lol
                    break; }*/

        break;
    case 4: // weekly progress
        // printf("beforefunc :  %d\n", curweek);
        weekly_prog_menu(planlen, &curweek, underweight, overweight, weekprog);
        // printf("afterfunc :  %d\n", curweek);
        break; // end of main menu switch case
    }

    return 0;
}

void main_menu(int *ptrmenu)
{
    printf("\n==========================\n"
           "       MENU Options\n"
           "==========================\n"
           "(1) Height and Weight + BMI\n"
           "(2) Ideal BMI Comparison\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress");
    printf("\nEnter choice: ");
    scanf("%d", &(*ptrmenu));
}