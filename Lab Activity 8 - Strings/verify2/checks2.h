#include <stdio.h>
#include <string.h>
#include <ctype.h> //for isdigit

int checkupper(char pass[100])
{
    int i = 0;
    while (i <= strlen(pass))
    {
        if (isupper(pass[i]) == 0)
        {
            i++;
        }
        else /*if (isupper(pass[i] != 0))*/
        {
            return 1;
        }
    }
    return 0;
}

int checklower(char pass[100])
{
    int i = 0;
    while (i <= strlen(pass))
    {
        if (islower(pass[i]) == 0)
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