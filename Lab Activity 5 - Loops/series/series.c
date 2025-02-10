#include <stdio.h>

int main ()
{
    int i=0,s=0,c=0;
    puts("give me a single positive integer");
    scanf("%d", &i);

    while (c<=i){
        s = s + c;
        c = c + 1;
    }

    printf ("%d is the summation of your integer", s);

    return 0;
}