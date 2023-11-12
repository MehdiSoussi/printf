#include "main.h"
#include <unistd.h>
/**
 * binary_numbers - a function
 * @d: input
 * Return: binary number
 */
int binary_numbers(int d)
{
int res = 0, reminder, pow = 1;

if(d < 0)
return d;

do
{
    reminder = d % 2;
    d = d / 2 ;
    res = reminder * pow + res;
    pow = pow * 10;
 } while (d != 0);

return (res);
}
