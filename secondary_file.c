#include "main.h"
#include <unistd.h>
/**
 * _strlen - a function
 * @s: input
 * Return: size
 */

int _strlen(const char *s)
{
	int size = 0;
	int i = 0;

	while (*(s + i) != '\0')
	{
		size++;
		i++;
	}
	return (size);
}
/**
 * print_number - a function
 * @n: input
 * @counter: input
 * Return: 0
 */

void print_number(int n, int *counter)
{
	int pow_lev = 0 * n;
	int number;
	int i;
	int diminishing = n;
	int is_negative = 0 * n;
	char neg = '-';
	char asc;

	if (n < 0)
	{
		n = n * -1;
		is_negative = 1;
	}
	do {
		diminishing = (diminishing - (diminishing % 10)) / 10;
		pow_lev++;
	} while (diminishing != 0);
	diminishing = n;
	if (is_negative)
	{
		write(1, &neg, 1);
		*counter = *counter + 1;
	}
	for (i = pow_lev - 1; i >= 0; i--)
	{
		number = diminishing / power(10, i);
		diminishing = diminishing - number * power(10, i);
		asc = number + 48;
		write(1, &asc, 1);
		*counter = *counter + 1;
	}
}
/**
 * power - a function
 * @ten: input
 * @to_the_power: input
 * Return: result
 */
int power(int ten, int to_the_power)
{
	int i;
	int result = ten;

	if (to_the_power == 0)
		return (1);
	for (i = 1 ; i < to_the_power ; i++)
		result = result * 10;
	return (result);
}
/**
 * write_and_count - a function
 * @string_to_write: input
 * @byte_to_write: input
 * @counter: input
 * @count: input
 * Return: result
 */
void write_and_count(const char *string_to_write, int byte_to_write,
		int *counter, int count)
{
	write(1, string_to_write, byte_to_write);
	*counter += count;
}
/**
 * hexqdecimal_numbers_pointers - a function
 * @d: input
 * @counter: input
 * @capital: input
 * Return: binary number
 */
void hexqdecimal_numbers_pointers(long int d, int *counter, int capital)
{
	long int quotient, remainder;
	long int i, j = 0;
	char hexadecimalnum[100];
	char inc = '0';
	long int c;


	quotient = d;

	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			if (capital == 1)
				hexadecimalnum[j++] = 87 + remainder;
			else
				hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / 16;
	}

	for (c = j; c < 8; c++)
	{
		write(1, &inc, 1);
		*counter += 1;
	}

	for (i = j - 1; i >= 0; i--)
	{
		write(1, &hexadecimalnum[i], 1);
		*counter += 1;
	}
}
/**
 * print_address - a function
 * @toprint: input
 * @counter: input
 * Return: binary number
 */
void print_address(void *toprint, int *counter)
{
	long int casted;

	casted = (long int) toprint;
	hexqdecimal_numbers_pointers(casted, counter, 1);
}
