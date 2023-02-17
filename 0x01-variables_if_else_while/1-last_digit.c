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
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
int x;
x = n % 10;
if (n > 5)
{
printf("Last digit of %d is %d and greater than 5\n", n, x);
}
else if (x == 0)
{
printf("Last digit of %d is %d and greater than 0\n", n, x);
}
else
{
printf("Last digit of %d is %d and less than 6 not 0\n", n, x);
}
return (0);
}
