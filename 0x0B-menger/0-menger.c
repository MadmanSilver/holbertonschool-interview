#include "menger.h"

/**
 * menger - creates a 2d menger sponge of a given level
 * @level: level of menger sponge to create
 */
void menger(int level)
{
	char c = '#';
	int x, y, h, length = pow(3, level);

	for (y = 0; y < length; y++)
	{
		for (x = 0; x < length; x++)
		{
			c = '#';
			for (h = 1; h < length; h *= 3)
				if (y / h % 3 == 1 && x / h % 3 == 1)
					c = ' ';
			putchar(c);
		}
		putchar('\n');
	}
}
