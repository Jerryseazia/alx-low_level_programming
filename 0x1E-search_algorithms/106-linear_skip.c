#include "search_algos.h"

/**
 * linear_skip - function of prototype
 * @list: input list
 * @value: value to search in
 * Return: index of the number
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *start;
if (list == NULL)
return (NULL);
start = list;
do {
list = start;
start = start->express;
printf("Value checked at index ");
printf("[%d] = [%d]\n", (int)start->index, start->n);
} while (start->express && start->n < value);
if (start->express == NULL)
{
list = start;
while (start->next)
start = start->next;
}
printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)list->index, (int)start->index);
while (list != start->next)
{
printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
if (list->n == value)
return (list);
list = list->next;
}
return (NULL);
}
