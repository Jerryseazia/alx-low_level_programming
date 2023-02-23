#include "main.h"
/**
 * print_most_numbers - prints numbers between 0 to 9
 * (neither 2 nor 4).
 * Return: no return.
 */
void print_most_numbers(void)
{
int l;
for (l = 48; l < 58; l++)
{
if (l != 50 && l != 52)
_putchar(l);
}
_putchar('\n');
}
