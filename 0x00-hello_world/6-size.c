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
long int f;
long long int j;
float a;
char c;
printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(i));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(f));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(j));
printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(a));
return (0);
}
