#include "hash_tables.h"

/**
 * hash_table_get - function of theprototype
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *temp;

	/* find index in hash table where key is */
	/* look through linked list to find matching key for value */

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	temp = (ht->array)[idx];
	while (temp != NULL && strcmp(temp->key, key) != 0)
		temp = temp->next;
	if (!temp)
		return (NULL);
	else
		return (temp->value);
}
