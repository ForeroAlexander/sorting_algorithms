#include "sort.h"
/**
 *insertion_sort_list - Sorting algoritm (insertion sort)
 *@list: double pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previus = NULL, *current = NULL, *tmp = NULL, *bigger = NULL;

	if (!list || *list)
		return;
	bigger = previus = *list;
	current = previus->next;
	while (bigger)
	{
		while (current)
		{
			if (previus->n > current->n)
			{
				if (previus->prev == NULL)
					*list = current;
				if (previus->prev)
					previus->prev->next = current;
				current->prev = previus->prev;
				previus->prev = current;
				previus->next = current->next;
				if (previus->next)
					previus->next->prev = previus;
				current->next = previus;

				tmp = previus;
				previus = current;
				current = tmp;
				print_list(*list);
			}
			previus = previus->next;
			current = current->next;
		}
		bigger = bigger->next;
		previus = *list;
		current = previus->next;
	}
}
