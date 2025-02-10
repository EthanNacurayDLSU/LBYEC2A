#include <stdio.h>

int main ()
{
    int i=0,s=0,c=0;
    puts("give me a single positive integer");
    scanf("%d", &i);

    puts ("the even numbers before your integer are : ");
    while (c<=i){
        if(s%2 == 0 && s !=0){
            printf("%d \n", s);
        }
        s = s + 1;
        c = c + 1;
    }

    return 0;
}