#include "hash_tables.h"

/**
 * key_index - function of the prototype
 * @key: key
 * @size: size of hash table array
 * Return: index where key/value pair is stored in hash table array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idix;

	if (size == 0)
		return (0);

	idix = hash_djb2(key);
	return (idix % size);
}
