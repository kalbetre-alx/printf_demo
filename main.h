#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct FormatType - Struct op
 *
 * @c: The character
 * @print_func: The function associated
 */
typedef struct FormatType
{
	char c;
	char *(*print_func)(va_list);
} Format;

int _printf(const char *format, ...);
char *print_string(va_list args);
char *print_char(va_list args);
char *print_decimal(va_list args);
char *print_percent(va_list args);

char *(*get_print_func(char c))(va_list);

int add_char_to_buffer(char *buffer, int buf_len, int *len, char c);
int add_str_to_buffer(char *buffer, int buf_len, int *len, char *str);
void close_buffer(char *buffer, int buf_len, int *len, va_list ls);

#endif
