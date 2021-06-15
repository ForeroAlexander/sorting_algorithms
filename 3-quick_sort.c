#include "sort.h"

/**
 *partition - Lomuto partition
 *@array: list of numbers
 *@start: where start
 *@end: where end
 *@size: size of the array
 *Return: Position
 */
int partition(int *array, int start, int end, size_t size)
{
	int start_aux, j, pivote, tmp;

	pivote = end;
	start_aux = start - 1;
	j = start;

	while (j <= end - 1)
	{
		if (array[j] < array[pivote])
		{
			start_aux++;
			if (array[j] != array[start_aux])
			{
				tmp = array[start_aux];
				array[start_aux] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
	if (array[start_aux + 1] != array[end])
	{
		tmp = array[start_aux + 1];
		array[start_aux + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (start_aux + 1);
}


/**
 * quick_sort_recursive - Quick sort algoritm
 *
 * @array: list of numbers
 * @start: where start
 * @end: where end
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int p;

	if (start >= end || size < 2)
		return;

	p = partition(array, start, end, size);
	quick_sort_recursive(array, start, p - 1, size);
	quick_sort_recursive(array, p + 1, end, size);
}

/**
 * quick_sort - Call the quick sort recursive
 *
 * @array: list of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
