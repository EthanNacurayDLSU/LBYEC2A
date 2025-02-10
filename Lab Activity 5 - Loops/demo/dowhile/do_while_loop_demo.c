#include <stdio.h>

int main()
{   
    int choice = 0; //do not assume this is zero, if there is no value assigned then the associated value is what was previously in the memory address
    //menu

    // do while vs simple why loop, dowhy execture condition first before the body
   do { //run once before condition check
        puts("");
        puts("========== Menu ==========\n");
        puts("1. Option 1");
        puts("2. Option 2");
        puts("3. Exit");
        puts(">> Enter your choice");
    
        scanf("%d", &choice);
        puts("\nbody of the loop");
    printf("choice = %d\n", choice);
    
    } while (choice !=3);
    
        
    //dry = dont repeat yourself. dont copy paste your code good lord
   
   
return 0;
}