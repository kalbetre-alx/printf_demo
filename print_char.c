#include "main.h"

/**
 * print_char - gets pointer to a string containing a character
 * @args: the arguments
 *
 * Return: a pointer to a string or NULL if it fails
 */
char *print_char(va_list args)
{
	char *str;
	char c = va_arg(args, int);

	if (c == 0)
		c = '\0';

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);

	*str = (char)c;
	*(str + 1) = '\0';
	return (str);
}
