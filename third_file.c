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
return -d;

do
{
    reminder = d % 2;
    d = d / 2 ;
    res = reminder * pow + res;
    pow = pow * 10;
 } while (d != 0);

return (res);
}
/**
 * octal_numbers - a function
 * @d: input
 * Return: binary number
 */
int octal_numbers(int d)
{
int res = 0, reminder, pow = 1;

do
{
    reminder = d % 8;
    d = d / 8 ;
    res = reminder * pow + res;
    pow = pow * 10;
 } while (d != 0);

return (res);
}
/**
 * octal_numbers - a function
 * @d: input
 * Return: binary number
 */
void hexqdecimal_numbers(int d, int *counter, int capital)
{
    int quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
 
 
    quotient = d;
 
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
        if(capital == 1)
            hexadecimalnum[j++] = 87 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
 
    for (i = j-1; i >= 0; i--)
    {
            write(1, &hexadecimalnum[i], 1);
            *counter += 1;
    }
}
