#include <stdio.h>
/**
 * main -C program that prints various types of inputs
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
double d;
char c;
printf("the size of an int is: %lu.\n", (unsigned long)sizeof(i));
printf("the size of an double is: %lu.\n", (unsigned long)sizeof(d));
printf("the size of an Char is: %lu.\n", (unsigned long)sizeof(c));
return (0);
}
