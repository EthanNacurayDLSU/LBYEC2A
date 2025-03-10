#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit

#define TRUE 1
#define FALSE 0

int checkupper(char pass[100])
{
    int i = 0;
    while (i < strlen(pass))
    {
        if (isupper(pass[i]) == FALSE)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int checklower(char pass[100])
{
    int i = 0;
    while (i < strlen(pass))
    {
        if (islower(pass[i]) == FALSE)
        {
            i++;
        }
        else 
        {
            return 1;
        }
    }
    return 0;
}

int checkdigit(char pass[100])
{
    int i = 0;
    while (i < strlen(pass))
    {
        if (isdigit(pass[i]) == FALSE)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int checkspecial(char pass[100])
{
int i = 0;
while (i < strlen(pass))
{
    if ((isalpha(pass[i]) != FALSE) || (isdigit(pass[i]) != FALSE))
    {
        i++;
    }
    else
    {
        return 1;
    }   
}
return 0;
}