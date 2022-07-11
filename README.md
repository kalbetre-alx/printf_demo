# Project Specs

This wiki is for a custom `_printf` function built in c.

## Platform

Platform : **Ubuntu 20.04**

Complier : `gcc`

Complier flags : `-Wall -Werror -Wextra -pedantic -std=gnu89 *.c`

Style Requirement Checker : [Betty](https://github.com/holbertonschool/Betty)


## Function Prototype

The custom _printf has the following prototype

```c
int _printf(const char *format, ...);
```

<aside>
💡 It returns the number of characters printed (excluding the null byte used to end output to strings) and it shall writes the output to the `stdout` (The standard output stream)

</aside>

## Simple Printing

The custom _printf handles most simple case of just printing a text passed to it without a formatting specification

```c
_printf("Some text")
```

## Character Escaping

Special characters such as `" ' % \ ...` need character escaping to be printed otherwise they should have a special meaning

Use backslash `\` as a escaping character

| Characters | Meaning |
| --- | --- |
| \ | escape character |
| \\ | prints the backslash character |
| “ | start or end of string |
| \” | prints double quote |
| % | start a format specification |
| \% | prints percent sign |

## Format Specification

Every format specification starts with a percent sign and ends with a letter `%`

```c
int x = 5;
_printf("x is %d\n", x);

// This will substitute the variable x in the string
```

## Supported Formatting

| Formatting | Meaning |
| --- | --- |
| %c | print a single character |
| %s | print a string of characters |
| %% | print percent sign. Is equivalent to `\%` |
| %d | print a decimal (base 10) number |
| %i | print an integer in base 10 |

## Authors

Kalkidan Betre (kalbetre-alx)

Seblewengel Endale (seblewengell)