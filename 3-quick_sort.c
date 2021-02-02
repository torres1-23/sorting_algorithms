#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: pointer to array to sort.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick_sorted(array, 0, size - 1, size);
}

/**
 * quick_sorted - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: pointer to array to sort.
 * @low: lowest index of array.
 * @high: highest idex of array.
 * @size: size of array.
 */
void quick_sorted(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sorted(array, low, pi - 1, size);
		quick_sorted(array, pi + 1, high, size);
	}
}

/**
 * partition - divides an array in order to sort it
 * according to Lomuto partition scheme.
 *
 * @array: pointer to array to sort.
 * @low: lowest index of array.
 * @high: highest idex of array.
 * @size: size of array.
 *
 * Return: Final partition index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
		}
	}
	if (i != j)
		swap(array, i + 1, high);
	print_array(array, size);
	return (i + 1);
}

/**
 * swap - swaps integers in an array.
 *
 * @array: pointer to array to sort.
 * @i: index of integer to sort.
 * @j: index of integer to sort.
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
