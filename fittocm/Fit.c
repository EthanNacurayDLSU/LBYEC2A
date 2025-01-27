#include <stdio.h>

int main ()
{
    float lft, lcm;
    printf ("Input Length in ft.");
    scanf ("%f", &lft);

    lcm = lft * 30.48;

    printf ("%.2f ft. = %.2f", lft, lcm);


    return 0;
}