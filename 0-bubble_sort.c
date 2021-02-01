#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @array: Pointer to array to sort.
 * @size: Size of array.
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, fg = 0;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		fg = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				fg = 1;
			}
		}
		if (fg == 0)
			break;
	}
}
