#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: pointer to pointer of head of double linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *nxt = NULL, *tmp = NULL;

	if (!list)
		return;
	nxt = head->next;
	while (nxt)
	{
		if (head->n > nxt->n)
		{
			tmp = head;
			swap_nodes(list, head, nxt);
			head = tmp->prev;
			nxt = tmp;
		}
		nxt = nxt->next;
		head = head->next;
		print_list(*list);
	}
}

/**
 * swap_nodes - Swap nodes in a double linked list.
 *
 * @head: pointer to pointer of head of double linked list.
 * @tmp: pointer to actual node.
 * @nxt: pointer to next node.
 */
void swap_nodes(listint_t **head, listint_t *tmp, listint_t *nxt)
{
	while (nxt && tmp->n > nxt->n)
	{
		if (nxt->next)
		{
			tmp->next = nxt->next;
			nxt->next->prev = tmp;
		}
		else
			tmp->next = NULL;
		tmp = tmp->prev;
		if (tmp)
		{
			nxt->prev = tmp;
			nxt->next = tmp->next;
			tmp->next = nxt;
			nxt->next->prev = nxt;
		}
		else
		{
			tmp = *head,
			nxt->next = tmp;
			tmp->prev = nxt;
			nxt->prev = NULL;
			*head = nxt;
			nxt = tmp->next;
		}
	}
}
