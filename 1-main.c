#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 * @array: Array to convert
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list = NULL, *node;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		node->n = array[i];
		node->next = NULL;
		node->prev = NULL;

		if (!list)
			list = node;
		else
		{
			listint_t *last = list;
			while (last->next)
				last = last->next;
			last->next = node;
			node->prev = last;
		}
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
