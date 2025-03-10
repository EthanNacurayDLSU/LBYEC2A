#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit
#include <conio.h> //for getch
#include "checks2.h"

/*Notes : there is no string data type in C, only character arrays*/

#define TRUE 1 //defining value of true and false just to make the core easier to read.
#define FALSE 0


int main()
{
    char password[100] = {'\0'}, errors[100] = {'\0'}; //{'\0'} makes an empty string

    printf("Enter your PASSWORD : ");
    fgets(password, 100, stdin); //instead of 100, i can use sizeof()
    password[strlen(password)-1] = '\0';
    //int p = 0;
    /*do // code copied from login.c
    {
        password[p] = getch(); //getch reads only one character from the user input
        if (password[p] != '\r') //\r is a carraige return and means its the start of a new line (ascii 13, returns to start of current line and overwrites content)
        {
            printf("*");//
        }
        p++;
    } while (password[p - 1] != '\r'); *///repeats the loop until the user has pressed the return key

    printf("|%s|", password);

    if (strlen(password) < 10)
    {
        strcat(errors, "length (needs at least 10 characters),");
    }

    if (checkupper(password) != TRUE)
    {
        strcat(errors, " uppercase letter,");
    }

  if(checklower(password) != TRUE)
    {
        strcat(errors, " lowercase letter,");
    }

   if(checkdigit(password) != TRUE)
   {
       strcat(errors, " digit,");
   }
    
   if(checkspecial(password) != TRUE)
   {
        strcat(errors, " special character");
   }

   if (strlen(errors) == 0)
   {
    //strcat(errors, "No Errors");
    puts("\nPassword is Strong");
   } else
   {
    printf("\nPassword is Weak. Missing : %s", errors); 
   }

    return 0;
}