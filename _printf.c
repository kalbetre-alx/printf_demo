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
	char* (*print_func)(va_list);
	int buf_idx = 0, str_len = 0, j = 0;
	char *buffer, *temp_str;

	buffer = malloc(sizeof(char) * 1024);
	if (format == NULL || buffer == NULL)
		return (-1);

	va_start(list, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			buf_idx = get_buffer_index(buffer, buf_idx);
			buffer[buf_idx++] = *format;
			format++;
			str_len++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			/* if (*format == '%')
			{
				buf_idx = get_buffer_index(buffer, buf_idx);
				buffer[buf_idx++] = *format;
				str_len++;
			} */
			else
			{
				print_func = get_print_func(*format);
				if (print_func == NULL)
				{
					buf_idx = get_buffer_index(buffer, buf_idx);
					buffer[buf_idx++] = '%';
					buffer[buf_idx++] = *format;
					str_len += 2;
				}
				else
				{
					temp_str = print_func(list);
					if (temp_str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (*format == 'c' && *temp_str == '\0')
					{
						buf_idx = get_buffer_index(buffer, buf_idx);
						buffer[buf_idx++] = '\0';
						str_len++;
					}
					j = 0;
					while (temp_str[j] != '\0')
					{
						buf_idx = get_buffer_index(buffer, buf_idx);
						buffer[buf_idx++] = temp_str[j];
						str_len++;
						j++;
					}
					free(temp_str);
				}
			}
			format++;
		}
	}
	write_buffer(buffer, buf_idx, list);
	return (str_len);
}
