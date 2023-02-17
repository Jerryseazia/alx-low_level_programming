#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int ch = 'a';
int CH = 'A';
for (ch = 'a'; ch <= 'z'; ch++)
putchar(ch);
for (CH = 'A'; CH <= 'Z'; CH++)
putchar(CH);
putchar('\n');
return (0);
}
