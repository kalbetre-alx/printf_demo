#include "main.h"
#include <unistd.h>

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
 * create_buffer - creates buffer to hold string until it's ready for print
 * Return: pointer to buffer created
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * add_char_to_buffer - adds a character to a buffer
 * @buffer: the buffer to add to
 * @buf_len: the length of the buffer
 * @len: the length of the string in the buffer
 * @c: the character to add
 *
 * Return: the new length of the the buffer
 */
int add_char_to_buffer(char *buffer, int buf_len, int *len, char c)
{
	if (buf_len > 1024)
	{
		write(1, buffer, buf_len);
		buf_len = 0;
	}
	buffer[buf_len] = c;
	*len = *len + 1;
	return (buf_len + 1);
}

/**
 * add_str_to_buffer - adds a string to a buffer
 * @buffer: the buffer to add to
 * @buf_len: the length of the buffer
 * @len: the length of the string in the buffer
 * @str: the string to add
 *
 * Return: the new length of the the buffer
 */
int add_str_to_buffer(char *buffer, int buf_len, int *len, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		buf_len = add_char_to_buffer(buffer, buf_len, len, str[i]);
		i++;
	}
	return (buf_len);
}

/**
 * close_buffer - writes buffer, frees the buffer and ends the argument list
 * @buffer: the buffer to add to
 * @buf_len: the length of the buffer
 * @len: the length of the string in the buffer
 * @ls: argument list
 *
 * Return: Nothing
 */
void close_buffer(char *buffer, int buf_len, int *len, va_list ls)
{
	buf_len = add_char_to_buffer(buffer, buf_len, len, '\0');
	write(1, buffer, buf_len);
	free(buffer);
	va_end(ls);
}
