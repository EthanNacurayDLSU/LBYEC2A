#include <stdio.h>

int dotid(int numb[])
{
    int dot = 0, i;
    for (i = 0; i < 8; ++i)
    {
        dot += numb[i] * (8 - i);
    }
    return dot;
}

int x(int number[])
{
    int xa = 0;
    xa = (dotid(number) / 11);
    return xa;
}
