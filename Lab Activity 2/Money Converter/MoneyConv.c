#include <stdio.h>

float U = 0.017, R = 1.75, S = 0.064, J = 2.67, conv; // taken as of 1/20/2025

int cur, amt;

int main()
{
    printf("Which Currency Do You Wish to Exchange From Peso?\n");
    printf(" | 1 = Russian Ruble | 2 = Saudi Riyal | 3 = Japanese Yen | 4 = US Dollar | \n");
    scanf("%d", &cur);

    printf("How many pesos would you like to exchange\n");
    scanf("%d", &amt);

    if (cur == 1)
    {
        conv = (R * amt);
        printf("%d PHP is %.2f RUB", amt, conv);
    }
    else if (cur == 2)
    {
        conv = (S * amt);
        printf("%d PHP is %.2f SAR", amt, conv);
    }
    else if (cur == 3)
    {
        conv = (J * amt);
        printf("%d PHP is %.2f JPY", amt, conv);
    } else if (cur == 4) 
    {
        conv = (U * amt);
        printf("%d PHP is %.2f USD", amt, conv);
    }
    else
    {
        printf("You did not input a valid currency");
    }

    return 0;
}