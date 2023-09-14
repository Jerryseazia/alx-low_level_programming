#include "search_algos.h"

/**
 * rec_search - function of the prototype
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int rec_search(int *array, size_t size, int value)
{
size_t half = size / 2;
size_t p;
if (array == NULL || size == 0)
return (-1);
printf("Searching in array");
for (p = 0; p < size; p++)
{
printf("%s %d", (p == 0) ? ":" : ",", array[p]);
}
printf("\n");
if (half && size % 2 == 0)
half--;
if (value == array[half])
{
if (half > 0)
return (rec_search(array, half + 1, value));
return ((int)half);
}
if (value < array[half])
return (rec_search(array, half + 1, value));
half++;
return (rec_search(array + half, size - half, value) + half);
}
/**
 * advanced_binary - function of the prototype
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
int x;
x = rec_search(array, size, value);
if (x >= 0 && array[x] != value)
return (-1);
return (x);
}
