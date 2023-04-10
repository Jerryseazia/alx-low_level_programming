#include "main.h"

/**
 * get_endianness -  endianness
 * Return: 0 |big endian, or 1 | small endian
 */
int get_endianness(void)
{
	int num;

	num = 1;
	if (*(char *)&num == 1)
		return (1);
	else
		return (0);
}

