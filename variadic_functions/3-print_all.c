#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char argument
 * @ap: the argument list
 */
void print_char(va_list *ap)
{
	printf("%c", va_arg(*ap, int));
}

/**
 * print_int - prints an int argument
 * @ap: the argument list
 */
void print_int(va_list *ap)
{
	printf("%d", va_arg(*ap, int));
}

/**
 * print_float - prints a float argument
 * @ap: the argument list
 */
void print_float(va_list *ap)
{
	printf("%f", va_arg(*ap, double));
}

/**
 * print_str - prints a string argument
 * @ap: the argument list
 */
void print_str(va_list *ap)
{
	char *s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_one - prints one argument matching a format char
 * @c: the format character
 * @ap: the argument list
 * @sep: the separator to print first
 *
 * Return: 1 if something was printed, 0 otherwise
 */
int print_one(char c, va_list *ap, char *sep)
{
	printer_t p[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_str},
		{0, NULL}
	};
	int j = 0;

	while (p[j].c)
	{
		if (p[j].c == c)
		{
			printf("%s", sep);
			p[j].f(ap);
			return (1);
		}
		j++;
	}
	return (0);
}

/**
 * print_all - prints anything
 * @format: list of the types of the arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *sep = "";

	va_start(ap, format);
	while (format && format[i])
	{
		if (print_one(format[i], &ap, sep))
			sep = ", ";
		i++;
	}
	va_end(ap);
	printf("\n");
}
