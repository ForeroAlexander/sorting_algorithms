#include "sort.h"

/**
 *quick_sort_recursive - Quick sort algoritm
 *@array: List of numbers
 *@start: dinamic variable
 *@end: dinamic variable
 *@size: size of the array
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int tmp, pivote, start_aux, end_aux;

	if (start >= end)
		return;

	pivote = array[(start + end) / 2];
	start_aux = start;
	end_aux = end;

	do {
		while (array[start_aux] < pivote && start_aux < end)
			start_aux++;
		while (array[end_aux] > pivote && end_aux > start)
			end_aux--;
		if (start_aux <= end_aux)
		{
			tmp = array[start_aux];
			array[start_aux] = array[end_aux];
			array[end_aux] = tmp;
			start_aux++;
			end_aux++;
			print_array(array, size);
		}
	} while (start_aux <= end_aux);
	if (start < end_aux)
		quick_sort_recursive(array, start, end_aux, size);
	if (end > start_aux)
		quick_sort_recursive(array, start_aux, end, size);
}

/**
 *quick_sort - Call the Quick sort algoritm
 *@array: List of numbers
 *@size: Size of the list of numbers
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
