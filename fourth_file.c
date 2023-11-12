#include "main.h"
#include <unistd.h>
/**
 * hexqdecimal_numbers_pointers - a function
 * @d: input
 * @counter: input
 * @capital: input
 * Return: binary number
 */
void hexqdecimal_numbers_pointers(int d, int *counter, int capital)
{
    int quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
    char inc = '0';
    int c;
 
 
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
 
    for(c = j; c <8; c++)
    {
            write(1, &inc, 1);
            *counter += 1;
    }

    for (i = j-1; i >= 0; i--)
    {
            write(1, &hexadecimalnum[i], 1);
            *counter += 1;
    }
}