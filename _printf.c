#include "main.h"
#include <unistd.h>

/**
 * _printf - prints a string
 * @format: the string to print
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int b_idx = 0, len = 0, result = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (format == NULL || buffer == NULL)
		return (-1);
	va_start(list, format);
	while (*format != '\0')
	{
		result = handle_frmt(format, buffer, &b_idx, &len, list);
		if (result < 0)
		{
			free(buffer);
			return (-1);
		}
		format += result;
	}
	write_buffer(buffer, b_idx, list);
	va_end(list);
	return (len);
}
