#include "main.h"
#include <stdio.h>
/**
 * clear_bit - set the value
 * @n: pointer to decimal
 * @index: index position
 * Return: 1 success, -1 error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	unsigned int hold;

	if (index > 64)
		return (-1);
	hold = index;
	for (i = 1; hold > 0; i *= 2, hold--)
		;

	if ((*n >> index) & 1)
		*n -= i;

	return (1);
}
