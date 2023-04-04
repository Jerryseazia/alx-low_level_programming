#include "lists.h"

/**
 * reverse_listint - function of the prototype
 * @head: pointer to the pointer of the head of the linked lists
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevnode = NULL, *node = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		return (*head);
	}
	while (*head != NULL)
	{
		node = (*head)->next;
		(*head)->next = prevnode;
		prevnode = *head;
		*head = node;
	}
	return (prevnode);
}
