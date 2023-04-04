#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - function of the prototype
 * @head: pointer to the pointer of the head of the linked list
 * @n: integer
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node, *endnode;

	node = malloc(sizeof(listint_t));

	if (node == NULL)
	{
		return (NULL);
	}
	node->n = n;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		endnode = *head;
		while (endnode->next != NULL)
		{
			endnode = endnode->next;
		}
		endnode->next = node;
	}
	return (node);
}
