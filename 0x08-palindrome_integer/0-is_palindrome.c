#include "palindrome.h"

/**
 * is_palindrome - Checks if an integer is a palindrome or not
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long int length = 1;

	while (n / length != 0)
		length *= 10;

	length /= 10;

	while (n % 10 == n / length)
	{
		if (length <= 10)
			return (1);

		n = n % length / 10;
		length /= 100;
	}

	return (0);
}
