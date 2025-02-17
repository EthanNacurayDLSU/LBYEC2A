#include <stdio.h>
#include <math.h>

int sum (int n, int numbers[]) {
    int i, sum=0;
    for(i=0; i<n; i++)
    {
        sum += numbers[i];
    }
    return sum;
}


float sdev (int n, int numbers[])
{
    int i, add=0;
    float dev = 0.0, mean;

    mean = (sum(n, numbers)/n);
    for (i=0; i<n; i++)
    {
        dev += pow(numbers[i]-mean, 2);
    }
    
    return sqrt(dev/(n-1));
}
