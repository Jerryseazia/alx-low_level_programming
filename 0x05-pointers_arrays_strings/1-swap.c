#include "main.h"

/**
 * swap_int - funtion to sawp int
 * @a: integer to be swapped
 * @b: integer to be swapped
 * Return: No return value
 */

void swap_int(int *a, int *b)
{
	int temnumb;

		temnumb = *a;
		*a = *b;
		*b = temnumb;
}
