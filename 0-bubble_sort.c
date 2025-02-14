#include "sort.h"

/**
 * swap - swaps values of pointers
 * @a: prointer
 * @b: pointer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts array bubbly
 * @array - array
 * @size - size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
}
