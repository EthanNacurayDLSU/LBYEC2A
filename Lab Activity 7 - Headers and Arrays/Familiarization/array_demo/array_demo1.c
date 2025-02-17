#include <stdio.h>

int main()
{
    int numbers[10], n, i;
    numbers[0] = 11;
    numbers[1] = 12;

    for (i=0; i<10; i++)
    {
        printf("Number %d = %d\n", i, numbers[i]);
    }
    return 0;
}