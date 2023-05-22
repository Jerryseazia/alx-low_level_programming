#include "main.h"

/**
 * _isalpha - both lower and upper
 * @c: int of lower and uppercase
 *
 * Return: Either 1 or 0
 */
int _isalpha(int c)
{
if ((c > 96 && c < 123) || (c > 64 && c < 91))
return (1);
else
return (0);
}

