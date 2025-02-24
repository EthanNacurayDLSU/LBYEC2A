#include <stdio.h>
#include <math.h>

int id1, id2, id3, id4, id5, id6, id7, id8, dotid, x;

int main()
{
  printf("========= DLSU ID Validity Checker =========\n\n");

  printf("Enter the 1st digit of your ID number\n");
  scanf("%d", &id1);
  printf("Enter the 2nd digit of your ID number\n");
  scanf("%d", &id2);
  printf("Enter the 3rd digit of your ID number\n");
  scanf("%d", &id3);
  printf("Enter the 4th digit of your ID number\n");
  scanf("%d", &id4);
  printf("Enter the 5th digit of your ID number\n");
  scanf("%d", &id5);
  printf("Enter the 6th digit of your ID number\n");
  scanf("%d", &id6);
  printf("Enter the 7th digit of your ID number\n");
  scanf("%d", &id7);
  printf("Enter the 8th digit of your ID number\n");
  scanf("%d", &id8);

  dotid = ((id1 * 8) + (id2 * 7) + (id3 * 6) + (id4 * 5) + (id5 * 4) + (id6 * 3) + (id7 * 2) + (id8 * 1));
  x = (dotid / 11);

  if (x < 16 && dotid % 11 == 0) // and logical operator (i have to explain this now because this wasnt taught in class). There is also '||' (or) and '!' (not)
  {
    printf("Valid Student ID, You May Enter!");
  }
  else if (x >= 16 && dotid % 11 == 0)
  {
    printf("Valid Faculty ID, You May Enter!");
  }
  else
  {
    printf("Warning! Counterfeit I.D.!");
  }

  return 0;
}
