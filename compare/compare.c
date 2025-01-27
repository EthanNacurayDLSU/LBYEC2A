#include <stdio.h>

int main()
{
    float value1, value2, max;
    printf ("please enter two values\n");
    scanf ("%f, %f", &value1, &value2);

        if (value1 > value2)
        {
            max = value1;
        } else
        {
            max = value2;
        }
        
    printf ("the largest value is %.2f", max);
    return 0;
}