#include "main.h"
#include <stdio.h>
/**
 * get_bit - get the value
 * @n: number to evaluate
 * @index: index
 * Return: Value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int hold;

	if (index > 64)
		return (-1);

	hold = n >> index;

	return (hold & 1);
}
