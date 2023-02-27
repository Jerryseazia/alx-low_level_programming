#include "main.h"
#include <stdio.h>

/**
 * print_rev - prints a string followed by a new line..
 *
 * @s: the string to print.
 * Return: void
 * done by sarah Irisoanga
 */

void print_rev(char *s)
{
	int num = 0;

	while (s[num])
	{
		num++;
	}
	while (num--)
	{
		putchar(s[num]);
	}
	putchar('\n');
}
