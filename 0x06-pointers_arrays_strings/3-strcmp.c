#include "main.h"

/**
 * _strcmp - function
 * @s1: char to be compressed
 * @s2: char to be compressed
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
