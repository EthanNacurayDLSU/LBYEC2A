#include <stdio.h>
#include <string.h>
#include "bmiformula.h"

#define TRUE 1
#define FALSE 0

int main()
{
    float bmi, h, w, lcal, gcal;                                                    // for bmi calculations
    int planlen = 8, curweek = 1;                                                   // length of exercise plan in weeks, curweek is current week of plan
    int overweight, underweight;
    int weekprog[3][16] = {0};

                                                                                    // login/signup variables
    char usernameinp[50], passwordinp[50];                                          // For username and password input
    char userst[50] = "/n", passwordst[50] = "/n";                                  // For stored username and password.
    int lschoice;                                                                   // For user's input in menu

                                                                                    // ASCII Text LOGO
    puts("\n\n\n");
    puts("  ____      _     _   _            _ _   _           _ ");
    puts(" / ___| ___| |_  | | | | ___  __ _| | |_| |__  _   _| |");
    puts("| |  _ / _ \\ __| | |_| |/ _ \\/ _` | | __| '_ \\| | | | |");
    puts("| |_| |  __/ |_  |  _  |  __/ (_| | | |_| | | | |_| |_|");
    puts(" \\____|\\___|\\__| |_| |_|\\___|\\__,_|_|\\__|_| |_|\\__, (_)");
    puts("                                               |___/   ");

    // login/signup options
    while (1){
    printf("======= Login/Signup =======\n");
    if (strcmp(userst, "/n") == 0 && strcmp(passwordst, "/n") == 0)
    {
        printf("No account found! Please sign up first.\n");
        lschoice = 2;                                                               // Forces user to signup menu if no account found
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
    if (lschoice == 1){                                                             // User Login
        printf("Enter Username: ");
        fgets(usernameinp, sizeof(usernameinp), stdin);
        usernameinp[strcspn(usernameinp, "\n")] = 0;

        printf("Enter Password: ");
        fgets(passwordinp, sizeof(passwordinp), stdin);
        passwordinp[strcspn(passwordinp, "\n")] = 0;

        if (strcmp(usernameinp, userst) == 0 && strcmp(passwordinp, passwordst) == 0)
        {
            printf("Login successful! Welcome, %s!\n", userst);
            break;                                                                  // Continue to menu system if credentials are correct
        }
        else
        {
            printf("Invalid credentials. Returning to Menu. . .\n");
            continue;                                                               // Return to login menu if input credentials do not match
        }
        }
    else if (lschoice == 2){                                                        // User Signup
        printf("Welcome to Get Healthy!\nPlease enter your chosen Username: ");

        fgets(usernameinp, sizeof(usernameinp), stdin);
        usernameinp[strcspn(usernameinp, "\n")] = 0;

        printf("Please enter your chosen Password: ");
        fgets(passwordinp, sizeof(passwordinp), stdin);
        passwordinp[strcspn(passwordinp, "\n")] = 0;

        strcpy(userst, usernameinp);                                                // Copy new username to storage
        strcpy(passwordst, passwordinp);                                            // Copy new password to storage
        printf("Signup was successful! Please login with your new account!\n");
        continue;                                                                   // Go back to the login menu so user can login again
        }
    else {
        printf("Invalid choice. Please try again.\n");
        continue;                                                                   // Return to login menu so user can try again
        }
    }

    /* Note that signing up in this case would overwrite the previous user. I think we could use arrays to store multiple users but that's beyond my forte right now.*/
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
    case 1:                                                                         // height and weight + BMI
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
    case 2:                                                                         // bmi value and classification, 7700 cal / kg
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
            printf("Your BMI is Healthy! Keep it up!");                             // cant you just like display this yourself?
        }
        goto menu;
        break;
    case 3:                                                                         // exercise/diet plan
        if (!(bmi < 18.5) && !(bmi > 24.9))   /* Is this conditional right? Idk.*/
        {                                                                           // Basically if user is already healthy, then no exercise or diet plan is needed.
            printf("Since you're already healthy, just maintain your current lifestyle!");
            break;                                                                  // I was thinking of letting it loop back to the menu but I'll keep it like this for now
        }
        /* Technically we *could* make a plan for them to maintain their BMI, but I can't wrap around my head on how to do that without complicating this further.  */
        else
        {
            printf("\n==========================\n"                                 // Nested switch for choosing what type of plan
                   "      PLAN MENU Options\n"                                      // Also a submenu
                   "==========================\n"
                   "(1) Exercise Plan\n"
                   "(2) Diet Plan\n");
            int xdplan;
            printf("\nEnter choice: ");
            scanf("%d", &xdplan);
            switch (xdplan) {                                                       
            case 1:                                                                 // Exercise Plan
                if (bmi < 18.5){                                                    // Prevents exercise plan if underweight
                    printf("You are already underweight! Please reconsider doing an exercise plan.");
                } else {
                    printf("\n===============================\n"
                           "      Choose Your Activity\n"
                           "===============================\n"
                           "(1) Walking\n"
                           "(2) Jogging\n"
                           "(3) Running\n"
                           "(4) Swimming\n");
                    int actplan;
                    printf("\nEnter choice: ");
                    scanf("%d", &actplan);
                    float hewalks, hejogs, heruns, heswims, minwalks, minjogs, minruns, minswims, hourwalk = 350, hourjog = 450, hourrun = 600, hourswim = 500,  // Variables for calculations. It might be inefficient I don't know I can't see my fingers.
                          loseweek = lcal / planlen;                                // Calculates hours needed to lose per week

                    switch (actplan) { /* I have not tested the calculations for these yet. Proceed with caution.*/
                        case 1:
                            hewalks = lcal / (planlen * hourwalk);            // Calculates hours needed to walk per week
                            minwalks = (hewalks * 60);                        // Converts hours to minutes
                            printf("You need to lose %.1f calories, which means you need to lose around %.1f calories per week.", lcal, loseweek);
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
            case 2:                                                                 // Diet Plan
                if (bmi > 24.9){                                                    // Prevents diet plan if overweight
                    printf("You are already overweight! Please reconsider doing a diet plan.");
                } else {
                    printf("\n===============================\n"
                           "      Choose Your Craving\n"
                           "===============================\n"
                           "(1) Chicken Nuggets\n"
                           "(2) Tuna\n"
                           "(3) Rice\n"
                           "(4) Broccoli\n");
                    int dtplan;
                    printf("\nEnter choice: ");
                    scanf("%d", &dtplan);
                    float onenugget = 302, onefish = 132, onerice = 130, onebroccoli = 34, servingsperweek;
                    float gainweek = gcal / planlen;

                    switch (dtplan) {
                        case 1:
                            servingsperweek = gainweek / onenugget;
                            printf("You need to gain %.1f calories, which means you need to gain around %.1f calories per week.", gcal, gainweek);
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
                printf("Invalid option. Please try again.\n"); /* Don't know how to make this loop back lol */
                break;
            }
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