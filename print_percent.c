#include "main.h"

/**
 * print_percent - gets pointer to a string containing a % character
 * @args: the arguments
 *
 * Return: a pointer to a string or NULL if it fails
 */
char *print_percent(va_list args __attribute__((unused)))
{
	char *str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);

	*str = '%';
	*(str + 1) = '\0';
	return (str);
}
