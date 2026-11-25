#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @ap: the argument list
 * @sep: the separator
 */
void print_char(va_list *ap, char *sep)
{
	printf("%s%c", sep, va_arg(*ap, int));
}

/**
 * print_int - prints an int
 * @ap: the argument list
 * @sep: the separator
 */
void print_int(va_list *ap, char *sep)
{
	printf("%s%d", sep, va_arg(*ap, int));
}

/**
 * print_float - prints a float
 * @ap: the argument list
 * @sep: the separator
 */
void print_float(va_list *ap, char *sep)
{
	printf("%s%f", sep, va_arg(*ap, double));
}

/**
 * print_str - prints a string
 * @ap: the argument list
 * @sep: the separator
 */
void print_str(va_list *ap, char *sep)
{
	char *s = va_arg(*ap, char *);

	if (!s)
		s = "(nil)";
	printf("%s%s", sep, s);
}

/**
 * print_all - prints anything
 * @format: list of the types of the arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	printer_t p[] = {
		{'c', print_char}, {'i', print_int},
		{'f', print_float}, {'s', print_str}, {0, NULL}
	};
	va_list ap;
	int i = 0, j;
	char *sep = "";

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (p[j].c && p[j].c != format[i])
			j++;
		if (p[j].c)
		{
			p[j].f(&ap, sep);
			sep = ", ";
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
