#include "main.h"
#include <stdio.h>
#include <limits.h>


int main(void)
{
int x = _printf("%b", -2);
printf("\n");
printf("%d", x);
    return 0;
}