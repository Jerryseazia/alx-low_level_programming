#include "main.h"
#include <stdio.h>
/**
 * _strlen - Entry, count string function
 *
 *@s: This is the parameter/ arguement to be counted
 *
 * Return: int on success
 */
int _strlen(char *s)
{
int count = 0;
while (s[count])
{
count++;
}
return (count);
}
