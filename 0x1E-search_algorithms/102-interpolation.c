#include "search_algos.h"

/**
 * interpolation_search - function of the prototype
 * @array: array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int interpolation_search(int *array, size_t size, int value)
{
size_t pos, low, high;
double v;
if (array == NULL)
return (-1);
low = 0;
high = size - 1;
while (size)
{
v = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
pos = (size_t)(low + v);
printf("Value checked array[%d]", (int)pos);
if (pos >= size)
{
printf(" is out of range\n");
break;
}
else
{
printf(" = [%d]\n", array[pos]);
}
if (array[pos] == value)
return ((int)pos);
if (array[pos] < value)
low = pos + 1;
else
high = pos - 1;
if (low == high)
break;
}
return (-1);
}
