#include "lists.h"
#include <stddef.h>

/**
 * listint_len - function of the prototype
 * @h: a pointer to thr head of the linked list
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t lenght = 0;

	while (h != NULL)
	{
		lenght++;
		h = h->next;
	}
	return (lenght);
}
