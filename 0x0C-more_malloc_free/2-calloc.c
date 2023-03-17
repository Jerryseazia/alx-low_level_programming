#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _calloc - function
 * @nmemb: unsigned int
 * @size: unsigned int
 * Return: NULL or result
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *result;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	result = malloc(nmemb * size);

	if (result == NULL)
	{
		return (NULL);
	}
	memset(result, 0, nmemb * size);
	return (result);
}
