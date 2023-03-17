#include "main.h"
/**
 * array_range - function
 * @min: minimun int
 * @max: maximum int
 * Return: NULL and the pointer
 */
int *array_range(int min, int max)
{
	int i, *array;

	if (min > max)
	{
		return (NULL);
	}
	array = malloc(sizeof(int) * (max - min + 1));

	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= max - min; i++)
	{
		array[i] = min + i;
	}
	return (array);
}
