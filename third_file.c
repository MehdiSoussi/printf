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

	if (d < 0)
		return (-d);

	do {
		reminder = d % 2;
		d = d / 2;
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
/**
 * print_with_S - a function
 * @toprint: input
 * @counter: input
 * Return: binary number
 */
void print_with_S(char *toprint, int *counter)
{
	int i = 0;
	char x = 92;
	char y = '0';
	char z = 'x';
	while(*(toprint+i) != '\0')
	{
		if(*(toprint+i) >= 127 || (*(toprint+i) > 0 && *(toprint+i) < 32))
		{
			write(1, &x, 1);
			write(1, &z, 1);
			*counter = *counter + 2;
			if(*(toprint+i) < 16)
			{
				write(1, &y , 1);
				*counter = *counter + 1;
			}
			hexqdecimal_numbers(*(toprint+i), counter, 0);
		}
		else{
			write(1, toprint+i, 1);
			*counter = *counter + 1;
		}
		i++;
	}
}
