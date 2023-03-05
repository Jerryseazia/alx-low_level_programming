#include "main.h"

/**
 * *_strchr - function
 * @s: is a char
 * @c: is a char
 * Return: to c, s, or NULL
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	else
	{
		return (NULL);
	}
}
