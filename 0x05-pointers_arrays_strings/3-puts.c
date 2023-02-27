#include "main.h"
#include <stdio.h>

/**
 * _puts - prints a string followed by a line..
 *
 *@str: the string to print.
 * Return: void
 */

void _puts(char *str)
{
	int numb;

	for (numb = 0; str[numb] != '\0'; numb++)
	{
		putchar(str[numb]);
	}
	putchar('\n');
}
