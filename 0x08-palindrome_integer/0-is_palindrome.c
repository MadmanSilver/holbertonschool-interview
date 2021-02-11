#include "palindrome.h"

/**
 * is_palindrome - Checks if an integer is a palindrome or not
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, tmp = n;

	while (tmp != 0)
	{
		rev = tmp % 10 + rev * 10;
		tmp /= 10;
	}

	if (rev == n)
		return (1);
	return (0);
}
