#include "main.h"

/**
 * sqrt_helper - tries successive numbers to find the square root
 * @n: the number
 * @i: the current candidate
 *
 * Return: the square root of n, or -1 if there is none
 */
int sqrt_helper(int n, int i)
{
	if (i > n / i)
		return (-1);

	if (i * i == n)
		return (i);

	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: the square root of n, or -1 if n has no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (0);

	return (sqrt_helper(n, 1));
}
