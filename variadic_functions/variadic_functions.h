#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct printer - maps a format char to a print function
 * @c: the format character
 * @f: the function that prints the argument
 */
typedef struct printer
{
	char c;
	void (*f)(va_list *ap);
} printer_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
int print_one(char c, va_list *ap, char *sep);
void print_all(const char * const format, ...);

#endif
