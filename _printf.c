#include "main.h"
#include <unistd.h>

/**
 * get_str - Get the string pointer from chars
 * @count: the number of elements
 *
 * Return: a char array of passed elements
 */
char *get_str(const int count, ...)
{
	va_list list;
	int i;
	char str[count + 1];
	char *ptr;

	va_start(list, count);
	for (i = 0; i < count; i++)
		str[i] = va_arg(list, int);

	str[i] = '\0';
	ptr = str;
	return (ptr);
}


/**
 * handle_frmt - processes normal formatting of a printf
 * @frmt: the format string
 * @buf: current buffer
 * @b_idx: current buffer index
 * @len: length of the string
 * @ls: argument list
 *
 * Return: number of chars read
 */
int handle_frmt(const char *frmt, char *buf, int *b_idx, int *len, va_list ls)
{
	char* (*print_func)(va_list);
	char *temp_str;
	int error_flag = 0, format_offset = 2;

	if (*frmt != '%')
	{
		len += add_str_to_buffer(buf, b_idx, get_str(1, (char)*frmt));
		format_offset = 1;
	}
	else
	{
		frmt++;
		error_flag = *frmt == '\0';
		if (error_flag)
			return (-1);
		print_func = get_print_func(*frmt);
		if (print_func == NULL)
			*len += add_str_to_buffer(buf, b_idx, get_str(2, '%', (char)*frmt));
		else
		{
			temp_str = print_func(ls);
			error_flag = temp_str == NULL;
			if (error_flag)
				return (-1);
			if (*frmt == 'c' && *temp_str == '\0')
				*len += add_str_to_buffer(buf, b_idx, get_str(1, '\0'));
			*len += add_str_to_buffer(buf, b_idx, temp_str);
			free(temp_str);
		}
	}
	return (format_offset);
}

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
	char *buffer, *temp_str;

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
