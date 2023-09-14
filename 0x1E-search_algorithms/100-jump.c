#include "search_algos.h"
#include <math.h>

/**
 * print_range - function of the prototype
 * @a: index before jump
 * @b: index after jump
 */
void print_range(size_t a, size_t b)
{
printf("Value found between indexes [%lu] and [%lu]\n", a, b);
}

/**
 * print_c - function of the prototype
 * @array: array
 * @c: index checked
 */
void print_c(int *array, size_t c)
{
printf("Value checked array[%lu] = [%d]\n", c, array[c]);
}

/**
 * jump_search - function of the prototype
 * @array: given array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int jump_search(int *array, size_t size, int value)
{
size_t jump = sqrt(size);
size_t a = 0;
size_t b = 0;
if (!array)
return (-1);
while (b <= size)
{
if (b != 0)
print_c(array, a);
if (array[b] >= value)
{
print_range(a, b);
while (a <= b)
{
print_c(array, a);
if (array[a] == value)
return (a);
a++;
}
return (-1);
}
if (b + jump + jump > size)
{
print_c(array, b);
print_range(b, b + jump);
while (b < size)
{
print_c(array, b);
if (array[b] == value)
return (b);
b++;
}
return (-1);
}
a = b;
b += jump;
}
return (-1);
}
