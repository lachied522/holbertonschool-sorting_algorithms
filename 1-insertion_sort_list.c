#include "sort.h"

/**
 * swap_nodes - swaps nodes in doubly linked list
 * @list: pointer to head of list
 * @a: pointer to first node
 * @b: pointer to second node
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	/* if 1st node exists, make next ptr 2nd node */
	if (a->prev != NULL)
		a->prev->next = b;
	/* If its the head, update to 2nd node */
	else
		*list = b;
	/* make sure 2nd node is not the tail, make prev ptr the 1st node */
	if (b->next != NULL)
		b->next->prev = a;

	/* Update pointers */
	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
}


/**
 * insertion_sort_list - sorts a singly linked list with insertion
 * @list - singly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* assume first item is sorted */
	curr = (*list)->next;

	while (curr != NULL)
	{
		prev = curr->prev;

		while (prev != NULL && curr->n < prev->n)
		{
			swap_nodes(list, prev, curr);
			print_list(*list);
			prev = curr->prev;
		}

		curr = curr->next;
	}
}
