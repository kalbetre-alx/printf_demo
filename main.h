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

/* Format Handler */
int handle_frmt(const char *frmt, char *buf, int *b_idx, int *len, va_list ls);

/* Buffer Helpers */
int get_buffer_index(char *buffer, int index);
void write_buffer(char *buffer, int len, va_list list);
int add_str_to_buffer(char *buffer, int *buf_idx, char *str);

#endif
