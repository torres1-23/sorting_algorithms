#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @array: Pointer to array to sort.
 * @size: Size of array.
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, fg = 1;
	int tmp = 1;

	while (fg == 1)
	{
		fg = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				fg = 1;
			}
		}
	}
}
