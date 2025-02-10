#include <stdio.h>
#include <ctype.h> //to use toupper or tolower
int main()
{
    char guess, actual='E';

    do
    {
        printf ("\nenter your guess : ");
        scanf("%c", &guess);

        if (toupper(guess) < actual)
        {
            printf ("Your guess is lower than my letter\n");
        } else if (toupper(guess) > actual)
        {
            printf ("Your guess is higher than my letter\n");
        }
        getchar(); //clears buffer so scanf doesnt break
    } while (toupper(guess) != actual);

printf ("YOU ARE CORRECT, MY LETTER IS %c", actual);
    
    return 0;
}