#include "main.h"

/**
 * *_memset - function
 * @s: a pointer to the memory area to fill with the constant byte
 * @b: the constant byte to fill the memory area with
 * @n: the number of bytes to fill with the constant byte
 * Return: to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
