#include <stdio.h>
#include <windows.h> //for Sleep command to do the second by second timer

int main()
{
    int i = 0;
    printf("countdown\n");
    printf("how many seconds to blastoff?\n");
    scanf("%d", &i);

    for (int t = i; t >= 0; t--)
    {
        printf("%d seconds left \n", t);
        Sleep(500); // sytem does nothing for 1000 miliseconds
    }
    puts("BLASTOFF!!!");
    return 0;
}