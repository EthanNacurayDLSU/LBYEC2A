#include <stdio.h>

int main()
{
    int i = 400, s = 0, c = 0;
    // puts("give me a single positive integer");
    // scanf("%d", &i);

   // puts("the even numbers before your integer are : ");
    while (c <= 400)
    {
        /*if (c % 2 == 0 && c != 0)
        {
            printf("%d \n", c);
            s = s + 1;
        }*/

        printf("%d \n", c);
        c = c + 1;
    }

    for (c; c <= i; c++)
    {
        if (c % 3 == 0 && c != 0)
        {
            // printf("%d \n", c);
            s = s + 1;
        }
    }
    //printf("The number of integers divisible by 3 is : %d", s);
    return 0;
}