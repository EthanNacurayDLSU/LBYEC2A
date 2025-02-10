#include <stdio.h>

int main()
{   
    //initialization
    int i=1;

    while (i<=10)//Stopping condition. if you put while(*any non zero value*) the loop will always be true. ex. while(10)
    {
        printf("i=%d ", i); //loop body
        i = i +1; //loop update, i++ also meants i=i+1
    }
    


return 0;
}