#include "sort.h"

/**
 * swap - swap elements of array
 * @a: pointer to first element
 * @b: pointer to second element
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partition function for quick sort
 * @array: full array
 * @low: start index of partition
 * @high: end index of partition
 * @size: size of full array for printing
 * Return: index of new pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j;

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	/* only swap when necessary */
	if (i != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_sort - conduct quick sort
 * @array: integer array
 * @low: low index
 * @high: high index
 * @size: size of full array
 * Return: nothing
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int pi; /* partition index */

	if (low < high)
	{
		pi = partition(array, low, high, size);

		recursive_sort(array, low, pi - 1, size);
		recursive_sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers, quickly
 * @array: integer array
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	recursive_sort(array, 0, size - 1, size);
}
