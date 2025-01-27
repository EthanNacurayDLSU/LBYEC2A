#include <stdio.h>

int main()
{
    printf("Enter four scores : ");
    float grade, m1, m2, m3, m4;
    scanf("%f %f %f %f", &m1, &m2, &m3, &m4);
    printf("m1= %.2f; m2=%.2f; m3=%.2f; m4=%.2f", m1, m2, m3, m4);

    grade = (m1 + m2 + m3 + m4);

    if (grade < 70)
    {
        printf("\nfail");
    }
    else
    {
        printf("\npass");
    }

    return 0;
}