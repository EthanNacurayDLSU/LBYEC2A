#include <stdio.h>
#include "statistics.h"

int main ()
{
    int numbers[10]; //n is the index of elements in the array. last is n-1. Each index corresponds to a space in memory allocated to the array. Here, there is 10 spaces for the array
    int n, i; 
    float mean;

    puts("how many numbers would you like to perform statistics on? (limit to 10 integers): ");
    scanf("%d", &n);

   if (n>10)
    {
        puts("ERROR : You are requesting too many numbers");
        return 0;
    }
    
    for(i=0; i<n; ++i){
        printf("enter number %d : ", i+1);
        scanf("%d", &numbers[i]);
    }
    
    for (i=0; i<n; ++i)
    {
        printf("Number %d = %d\n", i+1, numbers[i]);
    }


    printf("Sum = %.2f\n", sum(n, numbers));

    mean = (sum(n, numbers)/n);   
    printf("Mean = %.2f\n", mean);

    printf("Standard deviation = %.2f\n", sdev(n, numbers));

return 0;
}