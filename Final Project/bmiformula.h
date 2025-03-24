/*#include <stdio.h>
int main ()

bmi = w / (h * h);*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void heightweight(float *ptrh, float *ptrw, float *ptrbmi)
{
    printf("Please enter your height in meters : ");
    scanf("%f", &(*ptrh));

    printf("Please enter your weight in kilograms : ");
    scanf("%f", &(*ptrw));

    puts("");
    (*ptrbmi) = (*ptrw) / ((*ptrh) * (*ptrh));
    if ((*ptrbmi) < 18.5)
        printf("Your BMI is %.1f, You are Underweight.\n", (*ptrbmi));
    else if ((*ptrbmi) < 24.9)
        printf("Your BMI is %.1f, You are Healthy!\n", (*ptrbmi));
    else if ((*ptrbmi) < 29.9)
        printf("Your BMI is %.1f, You are Overweight.\n", (*ptrbmi));
    else if ((*ptrbmi) < 34.9)
        printf("Your BMI is %.1f, You are Obese.\n", (*ptrbmi));
    else if ((*ptrbmi) < 39.9)
        printf("Your BMI is %.1f, You are Severely Obese.\n", (*ptrbmi));
    else
        printf("Your BMI is %.1f, You are Morbiusly a Beast.\n", (*ptrbmi));
}

void bmiclass(float *ptrh, float *ptrw, float *ptrbmi, float *ptrgcal, float *ptrlcal, float *ptrgoptimal, float *ptrloptimal, int *ptrunderweight, int *ptroverweight)
{
    (*ptrgcal) = ((18.5 - (*ptrbmi)) * ((*ptrh) * (*ptrh))) * 7700;
    (*ptrlcal) = (((*ptrbmi) - 24.9) * ((*ptrh) * (*ptrh))) * 7700;
    (*ptrgoptimal) = ((*ptrgcal) / 7700);
    (*ptrloptimal) = ((*ptrlcal) / 7700);
    ;
    if ((*ptrbmi) < 18.5)
    {
        printf("Your BMI is Less than Optimal.\n");
        printf("At your Current weight of %.1f, you need to gain:\n", (*ptrw));
        printf("%.1f Calories, %.1f kg.\n", (*ptrgcal), (*ptrgoptimal));
        (*ptrunderweight) = TRUE;
    }
    else if ((*ptrbmi) > 24.9)
    {
        printf("Your BMI is Higher than what is Healthy.\n");
        printf("At your Current weight of %.1f, you need to lose:\n", (*ptrw));
        printf("%.1f Calories, %.1f kg.\n", (*ptrlcal), (*ptrloptimal));
        (*ptroverweight) = TRUE;
    }
    else
    {
        printf("Your BMI is Healthy! Keep it up!");
    }
}
