#include <stdio.h>
#include "my_header.h" //qoute marks for user defined headers, outside the standard c headers. Imports custom header file

int main ()
{
    printf("hello world\n");
    greet();
    return 0;
}

/*why header? so you can keep main program short, you offload all your functions in a header file
*/