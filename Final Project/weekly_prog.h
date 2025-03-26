#include <stdio.h>

#define TRUE 1
#define FALSE 0

void weekly_menu_text()
{

    printf("\n==========================\n"
           "   Weekly Progress Menu\n"
           "==========================\n"
           "(1) Enter This Week's Progress\n"
           "(2) See Weekly Progress Table\n"
           "(3) Return\n");

    printf("Enter choice: ");
}

void prog_report(int planlen, int *ptrcurweek, int underweight, int overweight, float weekprog[3][16], char thatstring[])
{
    if ((*ptrcurweek) <= planlen)
    {
        printf("\n===== Week %d Progress Report =====", *ptrcurweek);
        if (overweight == TRUE)
        {
            printf("\nEnter how many minutes of %s did you do this week (%d) : ", thatstring, *ptrcurweek); // if trying to lose weight
            scanf("%f", &weekprog[0][*ptrcurweek]);
        }
        else if (underweight == TRUE)
        {
            printf("\nEnter how many %s did you eat this week? (%d) : ", thatstring, *ptrcurweek);
            scanf("%f", &weekprog[0][*ptrcurweek]);
        }
        (*ptrcurweek)++;
    }
    else
    {
        printf("Your get_healthy.exe plan has ended. This is the end of your program.");
    }
}

void array_weekly(int planlen, float weekprog[3][16], float weektarget)
{
    for (int i = 0; i < planlen; i++)
    {
        (weekprog[1][i]) = weektarget;
    }
}

void prog_table(int planlen, float weekprog[3][16])
{
    printf("\n===== Week Progress Table =====\n\n");
    printf("|                        |");

    for (int i = 1; i <= planlen; i++)
    {
        printf("|  Week %d  |", i);
    }

    printf("\n|     Weekly Progress    |");
    for (int i = 1; i <= planlen; i++)
    {
        printf("| %8.1f |", weekprog[0][i]);
    }
}

/*
void weekly_prog_menu(int planlen, int *ptrcurweek, int underweight, int overweight, int weekprog[3][16], char thatstring[], float *ptrminsneed)
{
    puts("Weekly Progress was Chosen");
    int weekchoice;

    printf("\n==========================\n"
           "   Weekly Progress Menu\n"
           "==========================\n"
           "(1) Enter This Week's Progress\n"
           "(2) See Weekly Progress Table\n"
           "(3) Return\n");

    printf("Enter choice: ");
    scanf("%d", &weekchoice);

    switch (weekchoice)
    {
    case 1: // updating the progress of the week

        // float  foodcount; // exercise time and nugget count
        if (*ptrcurweek <= planlen)
        {
            printf("\n===== Week %d Progress Report =====", *ptrcurweek);
            if (overweight == TRUE)
            {
                printf("\nEnter how many minutes of %s did you do this week (%d) : ", thatstring, *ptrcurweek); // if trying to lose weight
                scanf("%f", &weekprog[0][*ptrcurweek]);
            }
            else if (underweight == TRUE)
            {
                printf("\nEnter how many %s did you eat this week? (%d) : ", thatstring, *ptrcurweek);
                scanf("%f", &weekprog[0][*ptrcurweek]);
            }
            (*ptrcurweek)++;
        }
        else
        {
            printf("Your get_healthy.exe plan has ended. This is the end of your program.");
        }

        // printf("aferinc : %d \n", *ptrcurweek);
        break;
    case 2: // see the weekly progress so far

        if (weekprog == {0})
        {
            for (int i = 0; i < planlen; i++)
            {
                weekprog[1][i] =
            }
        }

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
    case 3:
        break;
    }
}*/
