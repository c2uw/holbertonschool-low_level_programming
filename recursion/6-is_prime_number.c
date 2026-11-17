#include "main.h"

/**
 * prime_helper - checks divisors recursively
 * @n: the number to check
 * @i: the current divisor
 *
 * Return: 1 if no divisor is found, 0 otherwise
 */
int prime_helper(int n, int i)
{
	if (i > n / i)
		return (1);

	if (n % i == 0)
		return (0);

	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (prime_helper(n, 2));
}
