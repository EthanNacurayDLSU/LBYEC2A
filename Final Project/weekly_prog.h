#include <stdio.h>

#define TRUE 1
#define FALSE 0

void weekly_prog_menu(int planlen, int *ptrcurweek, int underweight, int overweight, int weekprog[3][16])
{
    puts("Weekly Progress was Chosen");
    int weekchoice;

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
    case 1: // updating the progress of the week

        float /*exertime,*/ foodcount; // exercise time and nugget count

        printf("\n===== Week %d Progress Report =====", *ptrcurweek);
        if (/*overweight == TRUE*/ 1)
        {
            printf("\nEnter how many minutes you ran/walked/jogged/swam this week (%d) : ", *ptrcurweek); // if trying to lose weight
            scanf("%f", &weekprog[0][*ptrcurweek]);
        }
        else if (underweight == TRUE)
        {
            printf("\nEnter how many [foods] did you eat this week? (%d) : ", *ptrcurweek);
            scanf("%f", &foodcount);
        }

        (*ptrcurweek)++;

        //printf("aferinc : %d \n", *ptrcurweek);
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

        break;
        // case 3:
        // goto menu; // option to return to the menu
        // break;
    }
}
