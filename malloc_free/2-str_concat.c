#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: the first string (NULL is treated as empty)
 * @s2: the second string (NULL is treated as empty)
 *
 * Return: a pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i;
	unsigned int j;

	if (s1 != NULL)
		while (s1[len1] != '\0')
			len1++;

	if (s2 != NULL)
		while (s2[len2] != '\0')
			len2++;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	for (j = 0; j < len2; j++)
		res[i + j] = s2[j];

	res[i + j] = '\0';

	return (res);
}
