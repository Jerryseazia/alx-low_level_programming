#include "search_algos.h"

/**
 * print_arr - function of the prototype
 * @array: array
 * @a: left index of original array
 * @b: right index of original array
 */
void print_arr(int *array, size_t a, size_t b)
{
	size_t p = 0;

	printf("Searching in array: ");
	for (p = a; p <= b; p++)
	{
		if (p != b)
			printf("%d, ", array[p]);
		else
			printf("%d\n", array[p]);
	}
}

/**
 * binary_search - function of the prototype
 * @array: array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t ab = 0;
	size_t a = 0;
	size_t b = size - 1;

	if (!array)
		return (-1);

	while (a <= b)
	{
		print_arr(array, a, b);
		ab = (a + b) / 2;
		if (array[ab] == value)
			return (ab);
		else if (array[ab] > value)
			b = ab - 1;
		else
			a = ab + 1;
	}
	return (-1);
}
