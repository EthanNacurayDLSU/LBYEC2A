#include <stdio.h>

int main()
{
    int arr[5] = {0};
    int i;

    for (i = 0; i < 5; ++i)
    {
        printf("Enter Number %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 5; ++i)
    {
        arr[i] = arr[i] * 10;
    }

    for (i = 0; i < 5; ++i)
    {
        printf("\nNumber %d = %d", i + 1, arr[i]);
    }
    return 0;
}