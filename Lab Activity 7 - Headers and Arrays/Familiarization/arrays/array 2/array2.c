#include <stdio.h>

int main()
{
    int num[5], i, max = 0;

    for (i = 0; i < 5; ++i)
    {
        printf("Enter Number %d : ", i + 1);
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 5; ++i)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }

    printf("\n The largest number is %d", max);

    return 0;
}