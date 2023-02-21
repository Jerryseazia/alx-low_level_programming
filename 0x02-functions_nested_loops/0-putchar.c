#include <stdio.h>
/**
 * main - prints the word _putchar
 * Return: return 0
 */
int main(void)
{
char word[9] = "_putchar";
int i = 0;
while (i < 8)
{
putchar(word[i]);
i++;
}
putchar('\n');
return (0);
}
