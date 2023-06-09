#include "hash_tables.h"

/**
 * hash_table_create - prototype of the function
 * @size: size
 * Return: pointer to table; NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtable;
	hash_node_t **array;
	unsigned long int x = 0;

	if (size == 0)
		return (NULL);

	hashtable = malloc(sizeof(hash_table_t));
	if (!hashtable)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(hashtable);
		return (NULL);
	}
	while (x < size)
	{
		array[x] = NULL;
		x++;
	}

	hashtable->size = size;
	hashtable->array = array;

	return (hashtable);
}
