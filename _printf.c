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
	va_list ls;
	int len = 0, buf_len = 0;
	char *(*print_func)(va_list);
	char *buffer, *temp_str;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (-1);
	if (format == NULL)
		return (-1);
	if ((*format == '%') && (*(format + 1) == '\0' || *(format + 1) == ' '))
		return (-1);

	va_start(ls, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			print_func = get_print_func(*format);
			if (print_func == NULL)
			{
				buf_len = add_char_to_buffer(buffer, buf_len, &len, '%');
				buf_len = add_char_to_buffer(buffer, buf_len, &len, *format);
			}
			else
			{
				temp_str = print_func(ls);
				buf_len = add_str_to_buffer(buffer, buf_len, &len, temp_str);
				free(temp_str);
			}
		}
		else
		{
			buf_len = add_char_to_buffer(buffer, buf_len, &len, *format);
		}
		format++;
	}
	close_buffer(buffer, buf_len, &len, ls);
	return (len - 1);
}
