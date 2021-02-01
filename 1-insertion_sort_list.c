#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: pointer to pointer of head of double linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *nxt = NULL, *prv = NULL;

	if (!list || *list == NULL|| (*list)->next == NULL)
		return;
	nxt = head->next;
	while (nxt)
	{
		prv = nxt->prev;
		while (prv && nxt->n < prv->n)
		{
			swap_nodes(list, &prv, nxt);
			print_list(*list);
		}
		nxt = nxt->next;
	}
}

/**
 * swap_nodes - Swap nodes in a double linked list.
 *
 * @head: pointer to pointer of head of double linked list.
 * @tmp: pointer to actual node.
 * @nxt: pointer to next node.
 */
void swap_nodes(listint_t **head, listint_t **tmp, listint_t *nxt)
{
	(*tmp)->next = nxt->next;
	if (nxt->next)
		nxt->next->prev = *tmp;
	nxt->prev = (*tmp)->prev;
	nxt->next = *tmp;
	if ((*tmp)->prev)
		(*tmp)->prev->next = nxt;
	else
		*head = nxt;
	(*tmp)->prev = nxt;
	*tmp = nxt->prev;
}
