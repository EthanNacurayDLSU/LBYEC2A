#include <stdio.h>
#include <string.h>
#include <conio.h> //for getchar

#define SIZE 100
#define user "Ethan"
#define passwd "John" // idk how to do password masking

int main()
{
    char username[SIZE], password[SIZE],
        name[SIZE], degree[SIZE], id[SIZE], address[SIZE], birthday[SIZE];

    printf("Enter your USERNAME : ");
    scanf("%[^\n]%*c", &username);

    printf("Enter your PASSWORD : ");
    int p = 0;
    do //i had to look this part up online
    {
        password[p] = getch();
        if (password[p] != '\r') //\r is a carraige return and returns the cursor back by one space
        {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');

    if (strcmp(username, user) == 0 || strcmp(password, passwd) == 0)
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
        puts("INVALID");
        return 0;
    }
}
