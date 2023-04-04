#include "lists.h"
#include <stdio.h>

/**
 * print_listint - function off the prototype
 * @h: pointer to the header
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t nodecount = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodecount++;
	}
	return (nodecount);
}
