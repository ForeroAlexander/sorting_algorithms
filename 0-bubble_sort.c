#include "sort.h"
/**
 *bubble_sort - Algoritm bubble
 *@array: list of numbers
 *@size: lenght of the Array
 *Return: Sorted array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, max_complex;
	int tmp;

        if (array == NULL || size == 0 || size == 1)
            return;

	for (max_complex = size - 1; max_complex > 0 ; max_complex--)
	{
		for (i = 0; i < max_complex; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}

	}
}
