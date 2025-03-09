#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int checkupper(char pass[100])
{
    int i = 0;
    do
    {
        if (isupper(pass[i]) == 0)
        {
            i++;
        }
        else if (isupper(pass[i] != 0))
        {
            return 0;
        }
    } while (i <= strlen(pass));
    return 1;
}

int main()
{
    char password[100] = {'\0'}, errors[100] = {'\0'};

    printf("Enter your PASSWORD : ");
    int p = 0;
    do // i had to look this part up online
    {
        password[p] = getch();
        if (password[p] != '\r') //\r is a carraige return and returns the cursor back by one space
        {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');

    if (strlen(password) <= 10)
    {
        strcat(errors, "length (needs at least 10 characters),");
    }

    if (checkupper(password) != 0)
    {
        strcat(errors, " uppercase letters,");
    }

    if (errors == '\0')
    {
        printf("No problems");
    }
    else
    {
        printf("\n%s", errors);
    }

    return 0;
}