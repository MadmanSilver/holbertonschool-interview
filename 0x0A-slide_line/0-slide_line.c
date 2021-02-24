#include "slide_line.h"

/**
 * slide_line - a function that slides and merges an array of integers
 * @line: array of integers
 * @size: size of line
 * @direction: direction to slide
 *
 * Return: 1 on success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		left(line, size);
	else if (direction == SLIDE_RIGHT)
		right(line, size);
	else
		return (0);

	return (1);
}

/**
 * right - a function that slides and merges an array of integers
 * @line: array of integers
 * @size: size of line
 */
void right(int *line, size_t size)
{
	size_t i = size - 2;
	size_t m = size - 1;

	for (; i != 0; i--)
	{
		if (line[i] == 0)
			continue;

		if (line[m] == line[i])
		{
			line[m] += line[i];
			line[i] = 0;
			m--;
		}
		else if (line[m] == 0)
		{
			line[m] = line[i];
			line[i] = 0;
		}
		else
			m--;
	}

	if (line[m] == line[i] || line[m] == 0)
	{
		line[m] += line[i];
		line[i] = 0;
	}
}

/**
 * left - a function that slides and merges an array of integers
 * @line: array of integers
 * @size: size of line
 */
void left(int *line, size_t size)
{
	size_t i = 1;
	size_t m = 0;

	for (; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		if (line[m] == line[i])
		{
			line[m] += line[i];
			line[i] = 0;
			m++;
		}
		else if (line[m] == 0)
		{
			line[m] = line[i];
			line[i] = 0;
		}
		else
			m++;
	}
}
