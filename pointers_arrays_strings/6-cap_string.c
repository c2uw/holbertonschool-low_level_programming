#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == ',' ||
		c == ';' || c == '.' || c == '!' || c == '?' ||
		c == '"' || c == '(' || c == ')' || c == '{' ||
		c == '}');
}

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: a pointer to str
 */
char *cap_string(char *str)
{
	int i = 0;
	int new_word = 1;

	while (str[i] != '\0')
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');

		new_word = is_separator(str[i]);
		i++;
	}

	return (str);
}
