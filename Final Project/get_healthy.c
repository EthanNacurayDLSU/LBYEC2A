#include <stdio.h>
#include <string.h>
#include "bmiformula.h"
#include "weekly_prog.h"
#include "exdie_plan.h"
#include "windows.h"
#include <conio.h>

#define TRUE 1
#define FALSE 0

void main_menu_text();
float calsum();

int main()
{
    float bmi = 0, h = 0, w = 0.0, lcal = 0, gcal = 0, loptimal = 0.0, goptimal = 0.0; // for bmi calculations

    int overweight = FALSE, underweight = FALSE; // This needs to stay.
    float weekprog[6][16] = {0.0};               // two dimensional array to store the weekly progress data.
    int planlen = 0, curweek = 1;                // length of exercise plan in weeks, curweek is current week of plan

    // login/signup variables
    char usernameinp[50], passwordinp[50];         // For username and password input
    char userst[50] = "/n", passwordst[50] = "/n"; // For stored username and password.
    int lschoice;                                  // For user's input in menu

    int exdiechoice = 4;
    float servingsweek = 0, gainweek = 0.0, hrsneed = 0, minsneed = 0, loseweek = 0.0;
    int exmchoice = 0, dtchoice = 0;
    char *thatstring = NULL;

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
    do
    {
        menu = 0;
        getch();
        main_menu_text();
        scanf("%d", &(menu));

        switch (menu)
        {
        case 1: // height and weight + BMI
            heightweight(&h, &w, &bmi, &overweight, &underweight, &menu);
            break;
        case 2: // bmi value and classification, 7700 cal / kg
            if (bmi == 0.0)
            {
                puts("\nYou have not entered your height and weight yet, please go back to the main menu");

                continue;
            }
            else
            {
                bmiclass(&h, &w, &bmi, &gcal, &lcal, &goptimal, &loptimal, &underweight, &overweight);
            }

            break;
        case 3: // exercise/diet plan

            if (loptimal != 0.0 || goptimal != 0.0)
            {
                while (1)
                {
                    printf("How many weeks long would you like your plan to be? : ");
                    scanf("%d", &planlen);

                    printf("\nLoading Exercise/Diet Plan Menu. . .\n");
                    checkPlan(underweight, overweight, &exdiechoice); // Function call for Initial ExDie Plan Check

                    switch (exdiechoice)
                    {
                    case 1:                                                                                        // Exercise Plan
                        exercisePlan(bmi, lcal, planlen, &exmchoice, &hrsneed, &minsneed, &loseweek, &thatstring); // Function call for Exercise Plan Menu
                        // printf("DEBUG: servingsweek:%f gainweek:%f hrsneed:%f minsneed:%f loseweek:%f exmchoice:%d dtchoice:%d thatstring:%s", servingsweek, gainweek, hrsneed, minsneed, loseweek, exmchoice, dtchoice, thatstring);
                        array_weekly(planlen, weekprog, minsneed);                                      // this function adds the weekly goal into the array
                        break;                                                                          // Go back to menu after
                    case 2:                                                                             // Diet Plan
                        dietPlan(bmi, gcal, planlen, &dtchoice, &servingsweek, &gainweek, &thatstring); // Function call for Exercise Plan Menu
                        // printf("DEBUG: servingsweek:%f gainweek:%f hrsneed:%f minsneed:%f loseweek:%f exmchoice:%d dtchoice:%d thatstring:%s", servingsweek, gainweek, hrsneed, minsneed, loseweek, exmchoice, dtchoice, thatstring);
                        array_weekly(planlen, weekprog, gainweek);
                        break;
                    case 3: // Go back to MAIN MENU
                        printf("Returning to the main menu...\n");
                        // goto menu; // CHANGE THIS IS NOT SAFE
                        break;
                    default: // Invalid option
                        printf("Invalid option. Please try again.\n");
                        continue;
                    }
                    break;
                }
            }
            else
            {
                puts("You have not seen your ideal BMI and classification yet. Returning to main menu. Please select menu option 2 before 3.");
                continue;
            }

            break;

        case 4: // weekly progress

            int weekchoice;
            puts("Weekly Progress was Chosen");
            do
            {
                weekchoice = 0;
                getchar();
                weekly_menu_text();
                scanf("%d", &weekchoice);

                switch (weekchoice)
                {
                case 1:
                    if ((curweek) <= planlen)
                    {
                        prog_report(planlen, &curweek, underweight, overweight, weekprog, thatstring, minsneed, servingsweek);
                    }
                    else
                    {
                        printf("Your get_healthy.exe plan has ended. This is the end of your program.\n");
                        printf("Please check your weekly progress table for your results\n");
                    }
                    // getchar();
                    break;

                case 2:

                    if (exdiechoice == 2) // diet plan
                    {
                        prog_table(planlen, weekprog, exdiechoice, dtchoice);
                    }
                    else if (exdiechoice == 1) // exercise plan
                    {
                        prog_table(planlen, weekprog, exdiechoice, exmchoice);
                    }

                    if (curweek > planlen)
                    {
                        if (exdiechoice == 2) // diet plan
                        {
                            printf("You gained %.2f calories over %d weeks\n", calsum(weekprog, planlen), planlen);
                            printf("Your target was to gain %.2f calories over %d weeks\n", gcal, planlen);
                        }
                        else if (exdiechoice == 1) // exercise plan
                        {
                            printf("You lost %.2f calories over %d weeks\n", (calsum(weekprog, planlen)), planlen);
                            printf("Your target was to lose %.2f calories over %d weeks\n", lcal, planlen);
                        }

                        if (!(lcal < calsum(weekprog, planlen)) || !(gcal < calsum(weekprog, planlen)))
                        {
                            puts("You have FAILED!!!");
                        }
                        else
                        {
                            puts("You have SUCCEEDED!!!");
                        }
                    }
                    break;
                }
            } while (weekchoice != 3);
            break; // end of main menu switch case

        default:
            printf("\nInvalid option. Please try again.\n");
            continue;
        }
    } while (menu != 5);

    printf("Closing Application");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        Sleep(200);
    }
    puts("\nThanks for using get_healthy.exe!!");

    return 0;
}
float calsum(float weekprog[6][16], int planlen)
{
    float caltotal = 0.0;
    for (int i = 1; i <= planlen; i++)
    {
        caltotal += weekprog[3][i];
    }
    return caltotal;
}

void main_menu_text()
{
    printf("\n==========================\n"
           "       MENU Options\n"
           "==========================\n"
           "(1) Height and Weight + BMI\n"
           "(2) Ideal BMI Comparison\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress\n"
           "(5) Exit Program");
    printf("\nEnter choice: ");
}