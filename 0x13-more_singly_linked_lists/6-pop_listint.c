#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop_listint - function of the prototype
 * @head: pointer to the pointer of the head of the linked list
 * Return: n or 0
 */

int pop_listint(listint_t **head)
{
	int info;
	listint_t *afternode;

	if (*head == NULL)
	{
		return (0);
	}
	info = (*head)->n;
	afternode = (*head)->next;
	free(*head);
	*head = afternode;
	return (info);
}
