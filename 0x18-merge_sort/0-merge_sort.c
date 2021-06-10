#include "sort.h"

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(sizeof(int) * size);

	sorter(array, size, tmp);
	free(tmp);
}

/**
 * sorter - does the actual sorting recursively
 * @arr: array of integers
 * @size: size of arr
 * @tmp: temporary array for recursive variable storage
 */
void sorter(int *arr, size_t size, int *tmp)
{
	size_t sl = size / 2, sr = size - sl;
	size_t i = 0, j = 0, k = 0;
	int *right = arr + sl;

	if (size <= 1)
		return;

	sorter(arr, sl, tmp);
	sorter(right, sr, tmp);

	for (i = 0; i < sl; i++)
		tmp[i] = arr[i];

	printf("Merging...\n[left]: ");
	print_array(arr, sl);

	printf("[right]: ");
	print_array(right, sr);

	i = 0;
	while (i < sl || j < sr)
	{
		while (j < sr && (i >= sl || right[j] < tmp[i]))
		{
			arr[k] = right[j];
			k++;
			j++;
		}

		while (i < sl && (j >= sr || tmp[i] <= right[j]))
		{
			arr[k] = tmp[i];
			k++;
			i++;
		}
	}

	printf("[Done]: ");
	print_array(arr, size);
}
