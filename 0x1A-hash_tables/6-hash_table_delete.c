#include "hash_tables.h"

/**
 * hash_table_delete - function of prototype
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx = 0;
	hash_node_t *node1, *nextnode;

	if (!ht)
		return;

	if (!(ht->array))
	{
		free(ht);
		return;
	}

	while (idx < ht->size)
	{
		node1 = (ht->array)[idx];
		while (node1)
		{
			nextnode = node1->next;
			if (node1->key)
				free(node1->key);
			if (node1->value)
				free(node1->value);
			node1->key = NULL;
			node1->value = NULL;
			free(node1);
			node1 = nextnode;
		}
		idx++;
	}
	free(ht->array);
	free(ht);
}
