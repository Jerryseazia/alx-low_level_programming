#include "lists.h"
#include <stdlib.h>
/**
 * add_dnodeint_end - function of the prototype
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *recent;
dlistint_t *end;
if (!head)
return (NULL);
recent = malloc(sizeof(struct dlistint_s));
if (!recent)
return (NULL);
recent->n = n;
if (*head == NULL)
{
*head = recent;
recent->next = NULL;
recent->prev = NULL;
return (recent);
}
end = *head;
while (end->next != NULL)
end = end->next;
recent->next = NULL;
recent->prev = end;
end->next = recent;
return (recent);
}
