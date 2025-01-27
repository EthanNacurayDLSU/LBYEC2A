#include <stdio.h>

float la, mp, pr, pe1, pe2;                  // raw values, float because half points are sometimes awarded
float cla, cmp, cpr, cpe1, cpe2, gpa, total; // computed values

int main()
{

    printf("LBYEC2A Total Grade Calculator\n");
    printf("REMINDER : ENTER ALL YOUR GRADES WITHOUT THE %% SYMBOL\n\n");

    printf("Enter your percent score for LAB ACTIVITIES\n");
    scanf("%f", &la);
    cla = (la * .2);

    printf("Enter your percent score for MACHINE PROBLEMS\n");
    scanf("%f", &mp);
    cmp = (mp * .2);

    printf("Enter your percent score for PROJECT\n");
    scanf("%f", &pr);
    cpr = (pr * .3);

    printf("Enter your percent score for PRACTICAL EXAM 1\n");
    scanf("%f", &pe1);
    cpe1 = (pe1 * .15);

    printf("Enter your percent score for PRACTICAL EXAM 2\n");
    scanf("%f", &pe2);
    cpe2 = (pe2 * .15);

    total = (cla + cmp + cpr + cpe1 + cpe2);

    if (total > 100)
    {
        printf("PLEASE ENTER A VALID GRADE, YOU DID NOT SCORE MORE THAN 100 PERCENT \n\n");
        printf("============================================================================================================================================\n\n");
        return 0;
    }

    if (total < 70) // There is probably a prettier way to do this than the yanderedev nested ifs... but i dont know how to do that "prettier way"
    {
        gpa = 0.0;
    }
    else if (total < 74)
    {
        gpa = 1.0;
    }
    else if (total < 78)
    {
        gpa = 1.5;
    }
    else if (total < 83)
    {
        gpa = 2.0;
    }
    else if (total < 88) // DOES NOT WORK IF YOUR GRADE IS EXACTLY 88 ON EVERYTHING AND I DONT KNOW HOW TO FIX IT ; LIKELHOOD IS TOO IMPROBABLE FOR ME TO CARE
    {
        gpa = 2.5;
    }
    else if (total < 92)
    {
        gpa = 3.0;
    }
    else if (total < 96)
    {
        gpa = 3.5;
    }
    else
    {
        gpa = 4.0;
    }

    printf("\n \nYour percentage breakdown is as follows : \n| LAB ACTIVITIES %.2f%% | MACHINE PROBLEMS %.2f%% | PROJECT %.2f%% | PRACTICAL EXAM 1 %.2f%% | PRACTICAL EXAM 2 %.2f%% |\n \n", cla, cmp, cpr, cpe1, cpe2);
    printf("Your total percent average is %.2f%% \nWhile your GPA is %.1f\n\n", total, gpa);
    if (gpa == 0.0)
    {
        printf("You FAILED!");
    }
    else
    {
        printf("You PASSED!");
    }

    return 0;
}
