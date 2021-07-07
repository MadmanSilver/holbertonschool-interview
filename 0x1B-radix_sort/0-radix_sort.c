#include "sort.h"

/**
 * radix_sort - sorts an array using radix algo
 * @array: array to sort
 * @size: size of array
 **/
void radix_sort(int *array, size_t size)
{
	int buck[10][10], buck_cnt[10];
	int j, k, digits = 0, div = 1, pass;
	size_t i;

	if (array == NULL || size == 1)
		return;

	pass = max(array, size);
	while (pass > 0)
	{
		digits++;
		pass /= 10;
	}

	for (pass = 0; pass < digits; pass++)
	{
		for (i = 0; i < 10; i++)
			buck_cnt[i] = 0;

		for (i = 0; i < size; i++)
		{
			j = (array[i] / div) % 10;
			buck[j][buck_cnt[j]] = array[i];
			buck_cnt[j] += 1;
		}

		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < buck_cnt[k]; j++, i++)
				array[i] = buck[k][j];
		}

		print_array(array, size);
		div *= 10;
	}
}

/**
 * max - gets the highest number in an array
 * @arr: array to search
 * @size: size of arr
 *
 * Return: highest number
 **/
int max(int *arr, size_t size)
{
	int max = arr[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];

	return (max);
}
