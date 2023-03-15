#include "main.h"

/**
 * *create_array - the function
 * @c: is a char
 * @size: unsidned interger
 * Return: to NULL or 0
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array = (char *) malloc(size * sizeof(char));

	if (size == 0)
	{
		return (NULL);
	}
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}
	return (array);
}
