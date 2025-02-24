#include <stdio.h>

int main ()
{
    int start, end;
    int mult[15];

    int index (int s, int e){
        for(int j=0; j<=e; ++j){
        mult[j-1] = s*j;
        }
    }

    

    puts("enter a start index (integer) : ");
    scanf("%d", &start);

    puts("enter a end index (integer) : ");
    scanf("%d", &end);

    //printf("   ");
    for (int i = 1; i <= end; i++)
    {
        printf("\t%d",  i);
    }
    printf("\n________");
    for (int i = 1; i <= end; i++)
    {
        printf("________");
    }
    for (int i = start; i <= end; i++)
    {
        
        
        index (i, end);
        printf("\n%d | ", i);

        for(int k=0; k<end; ++k)
        {
        printf("\t%d", mult[k]);
        }
    }

    return 0;
}