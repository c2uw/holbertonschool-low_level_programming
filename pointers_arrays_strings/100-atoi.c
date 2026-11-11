#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if no numbers are found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		else if (s[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}

	if (sign == 1)
		result = -result;

	return (result);
}
