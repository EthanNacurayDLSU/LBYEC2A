#include <stdio.h>
#include <math.h>
#include "verify.h"

int main()
{
  int i;
  int numbers[8] = {0};
  printf("========= DLSU ID Validity Checker =========\n\n");

  for (i = 0; i < 8; ++i)
  {
    printf("Enter ID Number %d Digit : ", i + 1);
    scanf("%d", &numbers[i]);
  }

  if (x(numbers) < 16 && dotid(numbers) % 11 == 0)
  {
    printf("Valid Student ID, You May Enter!");
  }
  else if (x(numbers) >= 16 && dotid(numbers) % 11 == 0)
  {
    printf("Valid Faculty ID, You May Enter!");
  }
  else
  {
    printf("Warning! Counterfeit I.D.!");
  }

  return 0;
}
