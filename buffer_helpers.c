#include "main.h"
#include <unistd.h>

/**
 * get_buffer_len - gets current buffer length, writes if overflow
 * @buffer: the buffer
 * @index: current index in buffer
 * 
 * Return: length position
 */
int get_buffer_index(char *buffer, int index)
{
	if (index < 1020)
		return (index);
	
	write(1, buffer, index);
	return (0);
}

/**
 * write_buffer - prints buffer, then frees it and frees va_list
 * @buffer: buffer holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len); /* realloc to correct size */
	write(1, buff, len);		 /* print */

	free(buff);
	va_end(list);
}

/**
 * add_str_to_buffer - adds a string to a buffer
 * @buffer: the buffer to add to
 * @buf_idx: the length of the buffer
 * @str: the string to add
 *
 * Return: the new length of the the buffer
 */
int add_str_to_buffer(char *buffer, int *buf_idx, char *str)
{
	int i, idx = *buf_idx;

	i = 0;
	while (str[i] != '\0')
	{
		idx = get_buffer_index(buffer, idx);
		buffer[idx] = str[i];
		idx++;
		i++;
	}

	*buf_idx = idx;
	return (i);
}
