#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - a function that produces output according to a format
 * @format: input
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, size = _strlen(format), counter = 0, string_length, number_toprint;
	char caractere_toprint, prc = '%', *string_toprint;
	int binary;
	va_list args;

	va_start(args, format);

	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (format[i] != '%')
			write_and_count(&format[i], 1, &counter, 1);
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					write_and_count(&format[i], 1, &counter, 1);
					break;
				case 'c':
					caractere_toprint = va_arg(args, int);
					write_and_count(&caractere_toprint, 1, &counter, 1);
					break;
				case 's':
					string_toprint = va_arg(args, char*);
					string_length = _strlen(string_toprint);
					write_and_count(string_toprint, string_length, &counter, string_length);
					break;
				case 'd':
				case 'i':
					number_toprint = va_arg(args, int);
					print_number(number_toprint, &counter);
					break;
				case 'b':
					number_toprint = va_arg(args, int);
					binary = binary_numbers(number_toprint);
					print_number(binary, &counter);
				break;	
				case 'o':
					number_toprint = va_arg(args, int);
					binary = octal_numbers(number_toprint);
					print_number(binary, &counter);
				break;	
				case 'u':
					number_toprint = va_arg(args, int);
					print_number(number_toprint, &counter);
				break;	
				case 'x':
					number_toprint = va_arg(args, int);
					hexqdecimal_numbers(number_toprint, &counter, 1);
				break;	
				case 'X':
					number_toprint = va_arg(args, int);
					hexqdecimal_numbers(number_toprint, &counter, 0);
				break;
				case 'S':
					string_toprint = va_arg(args, char*);
					print_with_S(string_toprint, &counter);
				break;

				default:
					write_and_count(&prc, 1, &counter, 1);
					write_and_count(&format[i], 1, &counter, 1);
					break;
			}
		}
	}
	va_end(args);
	return (counter);
}


