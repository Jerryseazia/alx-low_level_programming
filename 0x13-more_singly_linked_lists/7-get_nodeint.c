#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_nodeint_at_index - function of the prototype
 * @head: pointer to the head of the linked list
 * @index: is the index of the node, starting at 0
 * Return: 0 or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int nodecount = 0;
	listint_t *node = head;

	while (node != NULL && nodecount < index)
	{
		node = node->next;
		nodecount++;
	}
	if (nodecount == index && node != NULL)
	{
		return (node);
	}
	else
	{
		return (NULL);
	}
}
