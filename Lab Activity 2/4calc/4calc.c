#include <stdio.h>

float num1, num2, num3, num4, radd, rave, rsquare;
char confirm;

int main()
{
    printf("\n \n==================== NUMBER CALCULATOR THINGIMAJINGY ==================\n");
    printf("THIS IS A THINGY THAT ADDS, AVERAGES, AND ADDS THE SQUARES OF 4 NUMBERS\n");
    printf("=======================================================================\n\n");

numselect:
    printf("Please enter your 4 numbers : \n");
    scanf("%f %f %f %f", &num1, &num2, &num3, &num4);

numconfirm:
    printf("\nYour selected numbers are : n1 = %.3f, n2 = %.3f, n3 = %.3f, n4 = %.3f \n", num1, num2, num3, num4);
    printf("IS THIS CORRECT? Y/N \n");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y')
    {
        radd = (num1 + num2 + num3 + num4);
        rave = (radd / 4);
        rsquare = ((num1 * num1) + (num2 * num2) + (num3 * num3) + (num4 * num4));

        printf("SUM : %.3f\n", radd);
        printf("AVERAGE : %.3f\n", rave);
        printf("SUM OF ALL SQUARES : %.3f\n", rsquare);
        return 0;
    }
    else if (confirm == 'N' || confirm == 'n') // or operator
    {
        goto numselect;
    }
    else
    {
        printf("\n INVALID RESPONSE");
        goto numconfirm;
    }
}
