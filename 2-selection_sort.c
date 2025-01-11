#include "sort.h"

/**
 * selection_sort - sorts an array of integers with insertion
 * @array: integer array
 * @size: size of array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		/* set min index to current index */
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				/* update min index */
				min = j;
			}
		}

		/* only swap if necessary */
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
