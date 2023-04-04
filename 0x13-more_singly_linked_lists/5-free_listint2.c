#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function of the prototype
 * @head: pointer to the pointer of the head of a linked list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *node, *afternode;

	node = *head;

	while (node != NULL)
	{
		afternode = node->next;
		free(node);
		node = afternode;
	}
	*head = NULL;
}
