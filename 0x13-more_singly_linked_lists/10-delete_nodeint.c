#include "lists.h"

/**
 * delete_nodeint_at_index - function of the prototype
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node that should be deleted, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int nodecount = 0;
	listint_t *node, *prevnode;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	prevnode = *head;
	node = (*head)->next;
	while (node != NULL && nodecount < (index - 1))
	{
		prevnode = node;
		node = node->next;
		nodecount++;
	}
	if (nodecount == (index - 1) && node != NULL)
	{
		prevnode->next = node->next;
		free(node);
		return (1);
	}
	else
	{
		return (-1);
	}
}
