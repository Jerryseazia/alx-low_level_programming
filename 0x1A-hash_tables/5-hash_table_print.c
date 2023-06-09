#include "hash_tables.h"

/**
 * hash_table_print - function of the prototype
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	hash_node_t *node1;
	char *comma1 = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	while (idx < ht->size)
	{
		node1 = ((ht->array)[idx]);
		while (node1)
		{
			printf("%s'%s': '%s'", comma1, node1->key, node1->value);
			comma1 = ", ";
			node1 = node1->next;
		}
		idx++;
	}
	puts("}");
}
