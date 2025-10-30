#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			/* Swap nodes */
			listint_t *prev = tmp->prev;
			listint_t *next = tmp->next;

			if (prev->prev)
				prev->prev->next = tmp;

			tmp->prev = prev->prev;
			tmp->next = prev;
			prev->prev = tmp;
			prev->next = next;

			if (next)
				next->prev = prev;

			if (!tmp->prev)
				*list = tmp;

			print_list(*list);
		}
		current = current->next;
	}
}

