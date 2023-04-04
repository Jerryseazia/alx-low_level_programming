#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - function of the prototype
 * @head: pointer to the head of the linked list
 * Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *node, *afternode;

	node = head;

	while (node != NULL)
	{
		afternode = node->next;
		free(node);
		node = afternode;
	}
}
