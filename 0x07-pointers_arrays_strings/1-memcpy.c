#include "main.h"

/**
 * *_memcpy - function
 * @dest: destination of string
 * @src: the source of the string
 * @n: number of bytes
 * Return: to destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;

	while (n--)
	{
		*p++ = *src++;
	}
	return (dest);
}
