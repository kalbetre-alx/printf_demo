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

/* Buffer Helpers */
int get_buffer_index(char *buffer, int index);
void write_buffer(char *buffer, int len, va_list list);
int add_str_to_buffer(char *buffer, int *buf_idx, char *str);


int get_buffer_index_checked(char *buffer, int len);
char *create_buffer(void);
int add_char_to_buffer(char *buffer, int buf_len, int *len, char c);
void close_buffer(char *buffer, int buf_len, int *len, va_list ls);

#endif
