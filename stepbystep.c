#include "main.h"
#include <stdio.h>
#include <limits.h>


int main(void)
{
int x;

x = _printf("%X", 255);
printf("\n");
printf("%d", x);
printf("\n");

return 0;
}