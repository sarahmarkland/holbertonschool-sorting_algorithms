#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next; /*sets current ptr to 2nd node*/
	while (current != NULL) /*loops through list*/
	{
		next = current->next;
		prev = current->prev;
		/*if current node is less than previous node*/
		while (prev != NULL && prev->n > current->n)
		{
			/*swap nodes*/
			prev->next = current->next;
			if (current->next != NULL)
			/*if current node is not last node*/
				current->next->prev = prev;
			/*set current node to previous node*/
			current->next = prev;
			/*set previous node to current node*/
			current->prev = prev->prev;
			/*set previous node to current node*/
			prev->prev = current;
			/*if current node is first node*/
			if (current->prev == NULL)
			/*set head to current node*/
				*list = current;
			else
			/*set previous node to current node*/
				current->prev->next = current;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
