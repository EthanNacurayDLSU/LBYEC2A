#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit
#include <conio.h> //for getch
#include "checks2.h"

#define SIZE 100

int main()
{
    char password[100] = {'\0'}, errors[100] = {'\0'}; //{'\0'} makes an empty string
    char username[SIZE], name[SIZE], degree[SIZE], id[SIZE], address[SIZE], birthday[SIZE];
    char user[SIZE], pass[SIZE];

    puts("===== Account Creation =====");

    printf("Set your USERNAME : ");
    fgets(user, 100, stdin); //instead of 100, i can use sizeof()
    //getchar();
    user[strlen(user)-1] = '\0';

do {
    strcpy(errors, "");
    strcpy(password, "");
     
    printf("Set your PASSWORD : ");
    fgets(password, 100, stdin); //instead of 100, i can use sizeof()
    getchar();
    password[strlen(password)-1] = '\0';

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
    puts("\nPassword is Strong\n");
   
    } else
    {
    printf("\nPassword is Weak. Missing : %s\n", errors);
    }

} while (strlen(errors) != 0); 

    puts("===== Login =====");
   
    printf("Enter your USERNAME : ");
    scanf("%[^\n]%*c", &username);

    printf("Enter your PASSWORD : ");
    int p = 0;
    do // i looked this up online
    {
        pass[p] = getch(); //getch reads only one character from the user input
        if (pass[p] != '\r') //\r is a carraige return and means its the start of a new line (ascii 13, returns to start of current line and overwrites content)
        {
            printf("*");//when its not a new line, it replaces the typed line with an asterisk
        }
        p++;
    } while (pass[p - 1] != '\r'); //repeats the loop until the user has pressed the return key


    if (strcmp(username, user) == 0 || strcmp(password, pass) == 0)
    {
        puts("\n\nVALID\n");

        printf("Enter your Name : ");
        scanf("%[^\n]%*c", &name);

        printf("Enter your Degree Program : ");
        scanf("%[^\n]%*c", &degree);

        printf("Enter your Student ID no : ");
        scanf("%[^\n]%*c", &id);

        printf("Enter your Address : ");
        scanf("%[^\n]%*c", &address);

        printf("Enter your Birthday : ");
        scanf("%[^\n]%*c", &birthday);

        printf("\nHello %s!\n\n", name);

        puts("The following is your profile:\n");

        printf("Name: %s\n", name);
        printf("Degree Program : %s\n", degree);
        printf("Student ID no. : %s\n", id);
        printf("Address : %s\n", address);
        printf("Birthday : %s\n", birthday);

        return 0;
    }
    else
    {
        puts("\nINVALID");
        return 0;
    }
}