#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - a function that produces output according to a format
 * @format: input
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, size = _strlen(format), counter = 0, string_length, number_toprint;
	char caractere_toprint;
	char *string_toprint;
	va_list args;

	va_start(args, format);

	for (i = 0; i < size; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			counter++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					write(1, &format[i], 1);
					counter++;
					break;
				case 'c':
					caractere_toprint = va_arg(args, int);
					write(1, &caractere_toprint, 1);
					counter++;
					break;
				case 's':
					string_toprint = va_arg(args, char*);
					string_length = _strlen(string_toprint);
					write(1, string_toprint, string_length);
					counter += string_length;
					break;
				case 'd':
					number_toprint = va_arg(args, int);
					print_number(number_toprint, &counter);
					break;
				case 'i':
					number_toprint = va_arg(args, int);
					print_number(number_toprint, &counter);
					break;
				default:
					break;
			}
		}
	}
	va_end(args);
	return (counter);
}
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
