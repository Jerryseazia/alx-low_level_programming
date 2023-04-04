#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sum_listint - function of the prototype
 * @head: pointer to the head of the linked list
 * Return: 0
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *node = head;

	while (node != NULL)
	{
		sum += node->n;
		node = node->next;
	}
	return (sum);
}
