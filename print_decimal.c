#include "main.h"

/**
 * print_decimal - gets a pointer to a string containing the number
 * @args: the arguments
 *
 * Return: a pointer to a string or NULL if it fails
 */
char *print_decimal(va_list args)
{
	char *str;
	int num = va_arg(args, int);
	int is_neg = 0, i = 0;
	unsigned int unum, pow = 1, len = 0;

	if (num < 0)
	{
		is_neg = 1;
		len++;
		unum = (unsigned int)-num;
	}
	else
	{
		unum = (unsigned int)num;
	}

	while (pow <= (unum / 10))
	{
		pow *= 10;
		len++;
	}

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	if (is_neg)
	{
		*str = '-';
		i++;
	}
	while (pow > 0)
	{
		str[i] = (unum / pow) + '0';
		unum %= pow;
		pow /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
