#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit
#include <conio.h>
//#include "checks.h"

/*Notes : there is no string data type in C, only character arrays*/

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

int checklower(char pass[100])
{
    int i = 0;
    do
    {
        if (islower(pass[i]) == 0)
        {
            i++;
        }
        else if (islower(pass[i] != 0))
        {
            return 0;
        }
    } while (i <= strlen(pass));
    return 1;
}

int checkdigit(char pass[100])
{
    int i = 0;
    do
    {
        if (isdigit(pass[i]) == 0)
        {
            i++;
        }
        else if (isdigit(pass[i] != 0))
        {
            return 0;
        }
    } while (i <= strlen(pass));
    return 1;
}

int checkspecial(char pass[100])
{
    int i = 0;
    do
    {
        if (isalpha(pass[i]) == 0 || isdigit(pass[i]) == 0)
        {
            i++;
        }
        else
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

    // getchar();

    if (strlen(password) <= 10)
    {
        strcat(errors, "length(needs at least 10 characters),");
    }

    if (checkupper(password)!=0)
    {
        strcat(errors, " uppercase letter,");
    }

    if(checklower(password)!=0)
    {
        strcat(errors, " lowercase letter,");
    }

   // if(checkdigit(password)!=0)
   // {
   //     strcat(errors, " digit,");
   // }
    
    //if(checkspecial(password)!=0)
   // {

   //     strcat(errors, " special character,");
   // }

    /*if (errors == '\0')
    {
        printf("No problems");
    }
    else
    {
        printf("\n Missing : %s", errors);
    }*/

    printf("\n%s", errors);

    return 0;
}