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
void write_and_count(const char *string_to_write, int byte_to_write , int *counter, int count)
{
write(1, string_to_write, byte_to_write);
*counter += count;
}
