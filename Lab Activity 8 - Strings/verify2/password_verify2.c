#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit
#include <conio.h>
//#include "checks.h"

/*Notes : there is no string data type in C, only character arrays*/




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
        puts("length");
    }

    if (checkupper(password)!= 1)
    {
        strcat(errors, " uppercase letter,");
        puts("upper");
    }

  if(checklower(password)!=0)
    {
        strcat(errors, " lowercase letter,");
    }

   if (strlen(errors) == 0)
   {
    strcat(errors, "No Errors");
    puts("no error");
   }
    printf("\n%s", errors); 

    return 0;
}