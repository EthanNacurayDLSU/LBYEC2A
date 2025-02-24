#include <stdio.h>

int dotid(int numb[])
{
    int dot = 0, i;
    for (i = 0; i < 8; ++i)
    {
        dot += numb[i] * (8 - i); //	Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand. you can replace the + symbols with - * / to subtract, multiply, and divide instead of add
    }
    return dot;
}

int x(int number[])
{
    int xa = 0;
    xa = (dotid(number) / 11);
    return xa;
}
