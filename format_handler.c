#include "main.h"

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
	int is_null = 0;

	if (*frmt != '%')
	{
		*b_idx = get_buffer_index(buf, *b_idx);
		buf[(*b_idx)++] = *frmt;
		(*len)++;
		return (1);
	}
	else
	{
		frmt++;
		if (*frmt == '\0')
			return (-1);
		print_func = get_print_func(*frmt);
		if (print_func == NULL)
		{
			*b_idx = get_buffer_index(buf, *b_idx);
			buf[(*b_idx)++] = '%';
			buf[(*b_idx)++] = *frmt;
			*len += 2;
		}
		else
		{
			is_null = (temp_str = print_func(ls)) == NULL;
			if (is_null)
				return (-1);
			if (*frmt == 'c' && *temp_str == '\0')
			{
				*b_idx = get_buffer_index(buf, *b_idx);
				buf[(*b_idx)++] = '\0';
				(*len)++;
			}
			*len += add_str_to_buffer(buf, b_idx, temp_str);
			free(temp_str);
		}
		return (2);
	}
}
