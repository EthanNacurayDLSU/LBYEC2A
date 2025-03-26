#include <stdio.h>

#define TRUE 1
#define FALSE 0

void difference();
void weekcaltable();

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

void prog_report(int planlen, int *ptrcurweek, int underweight, int overweight, float weekprog[6][16], char thatstring[], float minsneed, float servingsweek)
{

    printf("\n===== Week %d Progress Report =====", *ptrcurweek);
    if (overweight == TRUE)
    {
        printf("\nEnter how many minutes of %s did you do this week (%d) : ", thatstring, *ptrcurweek); // if trying to lose weight
        scanf("%f", &weekprog[0][*ptrcurweek]);

        if ((weekprog[0][*ptrcurweek]) < minsneed)
        {
            puts("\nYou feel below your weekly goal. You need to work harder next week!");
        }
        else
        {
            puts("\nYou have reached weekly goal. Keep up the good work!");
        }
    }
    else if (underweight == TRUE)
    {
        printf("\nEnter how many %s did you eat this week? (%d) : ", thatstring, *ptrcurweek);
        scanf("%f", &weekprog[0][*ptrcurweek]);
        if ((weekprog[0][*ptrcurweek]) < servingsweek)
        {
            puts("You feel below your weekly goal. You need to work harder next week!");
        }
        else
        {
            puts("You have reached your weekly goal. Keep up the good work!");
        }
    }
    (*ptrcurweek)++;
}

void array_weekly(int planlen, float weekprog[6][16], float weektarget)
{
    for (int i = 0; i <= planlen; i++)
    {
        (weekprog[1][i]) = weektarget;
    }
}

void prog_table(int planlen, float weekprog[6][16], int exdiechoice, int dexmchoice)
{
    printf("\n===== Week Progress Table =====\n");
    printf("|                      |");

    for (int i = 1; i <= planlen; i++)
    {
        printf("|  Week %d  |", i);
    }

    printf("\n|    Weekly Progress   |");
    for (int i = 1; i <= planlen; i++)
    {
        printf("| %8.1f |", weekprog[0][i]);
    }

    printf("\n|     Weekly Target    |");
    for (int i = 1; i <= planlen; i++)
    {
        printf("| %8.1f |", weekprog[1][i]);
    }

    difference(planlen, weekprog);

    printf("\n|  Weekly Difference   |");
    for (int i = 1; i <= planlen; i++)
    {
        printf("| %8.1f |", weekprog[2][i]);
    }

    weekcaltable(weekprog, dexmchoice, exdiechoice, planlen);

    if (exdiechoice == 2) // diet plan
    {
        printf("\n|   Calories Gained    |");
        for (int i = 1; i <= planlen; i++)
        {
            printf("| %8.1f |", weekprog[3][i]);
        }
    }
    else if (exdiechoice == 1) // exercise plan
    {
        printf("\n|   Calories Burned    |");
        for (int i = 1; i <= planlen; i++)
        {
            printf("| %8.1f |", weekprog[3][i]);
        }
    }

    printf("\n\n");
}

void weekcaltable(float weekprog[6][16], int dexmchoice, int exdiechoice, int planlen)
{
    if (exdiechoice == 2) // diet plan
    {
        float calLose[] = {302, 132, 130, 34};
        for (int i = 1; i <= planlen; i++)

        {
            (weekprog[3][i]) = ((calLose[dexmchoice - 1]) * (weekprog[0][i]));
        }
    }
    else if (exdiechoice == 1) // exercise plan
    {
        float calBurn[] = {350, 450, 600, 500};
        for (int i = 1; i <= planlen; i++)
        {
            (weekprog[3][i]) = ((calBurn[dexmchoice - 1]) * (weekprog[0][i] / 60));
        }
    }
}

void difference(int planlen, float weekprog[6][16])
{
    for (int i = 1; i <= planlen; i++)
    {
        weekprog[2][i] = ((weekprog[0][i]) - (weekprog[1][i]));
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
