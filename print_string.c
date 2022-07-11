#include "main.h"
#include <string.h>

/**
 * print_string - get a pointer to a string containing the passed string
 * @args: the arguments
 *
 * Return: pointer to a string or NULL if it fails
 */
char *print_string(va_list args)
{
	char *str;
	char *s_arg = va_arg(args, char *);
	int len;

	if (s_arg == NULL)
		s_arg = "(null)";

	len = strlen(s_arg);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	return (strcpy(str, s_arg));
}
