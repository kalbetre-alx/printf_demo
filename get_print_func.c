#include "main.h"

/**
 * get_print_func - returns the print function for the given format.
 * @c: the format to get the print function for.
 *
 * Return: The print function for the given format specifier.
 */
char *(*get_print_func(char c))(va_list)
{
	Format formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_decimal},
		{'i', print_decimal},
		{'%', print_percent},
		{'\0', NULL}};
	int i = 0;

	while (formats[i].c != '\0')
	{
		if (formats[i].c == c)
			return (formats[i].print_func);
		i++;
	}
	return (NULL);
}
