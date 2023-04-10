#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	int counter;

	diff = n ^ m;
	counter = 0;

	while (diff)
	{
		counter++;
		diff &= (diff - 1);
	}

	return (counter);
}

