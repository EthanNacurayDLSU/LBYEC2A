#include <stdio.h>

int main ()
{
    int card[16] = {0};
    //4,1,4,7,2,0,3,0,5,9,7,8,0,9,4,2 | test number sir gave
    int odd=0, even=0, add;

//user inputs their credit card number
    for (int i = 0; i < 16; ++i)
    {
        printf("Enter Credit card Number %d Digit : ", i + 1);
        scanf("%d", &card[i]);
    }
//loop to access each address on the array
    for (int i = 0; i < 16; i++)
    {
        //checks if it is even or odd
        if (i%2!=0){
            even += card[i]; //if even, then it is simply summed up
            //printf("%d", card[i]);
            
        } else
        {
            odd += ((card[i])*2); // if oddm then it is doubled then summed up
           //printf("%d", card[i]);
        }
    }

    //debugging5
   //printf("\n%d", even);
   //printf("\n%d", odd); 

   add = odd+even; //taking the sum of both even and odd. in hindsight unnecessary

//determining the validity
   if (add%10 == 0)
   {
    puts("This card number is Valid");
   } else
   {
    puts("This card number is not Valid");
    }

    return 0;
}