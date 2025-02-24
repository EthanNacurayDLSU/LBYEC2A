#include <stdio.h>

int main()
{
    int h = 0, c, d=0, e=0;//h is height, c is series added to height to determine number of letters in a
    char i = 65;
    puts("Enter the height of your inverted pyramid");
    scanf("%d", &h);
    
    c = h-1;

    while (h>0)
    {
        
        puts("");
        i = 65;
        e = 0;
        do //code to add spaced before each new line to center it
        {
            printf(" ");
            e = e+1;
        } while (e <= d);
        while ((i-65) < (c+h))
        {
        printf("%c ", i);
        i = i+1;
        }
        h = h-1;
        c = c-1;
        d = d+2;
    }
return 0;
}