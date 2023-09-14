#include "search_algos.h"
#include <math.h>

/**
 * move_forward - function of the prototype
 * index, or the last node in the list
 * @list: list to move forward
 * @index: desired index
 * Return: node with desired index, or last node in the list
 */
listint_t *move_forward(listint_t *list, size_t index)
{
while (list->next != NULL && list->index < index)
list = list->next;
return (list);
}
/**
 * jump_list - function of the prototype
 * integers using the Jump search algorithm
 * @list: input list
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t jump;
listint_t *left, *right;
if (list != NULL && size > 0)
{
jump = sqrt(size);
left = list;
right = move_forward(left, jump);
printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
while (right->index < (size - 1) && right->n < value)
{
left = right;
right = move_forward(left, right->index + jump);
printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
}
printf("Value found between indexes [%lu] and [%lu]\n",
left->index, right->index);
printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
while (left->index < size - 1 && left->n < value)
{
left = left->next;
if (left == NULL)
return (NULL);
printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
}
if (left->n == value)
return (left);
}
return (NULL);
}
