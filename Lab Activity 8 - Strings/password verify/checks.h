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
