#include "hash_tables.h"

/**
 * create_and_add_node - function of the prototype
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * @idx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
			unsigned long int idx)
{
	hash_node_t *node1 = NULL;
	char *x;
	char *v;

	node1 = malloc(sizeof(hash_node_t));
	if (!node1)
		return (0);

	x = strdup(key);
	if (!x)
	{
		free(node1);
		return (0);
	}

	v = strdup(value);
	if (!v)
	{
		free(x);
		free(node1);
		return (0);
	}

	node1->key = x;
	node1->value = v;

	if ((ht->array)[idx] == NULL)
		node1->next = NULL;
	else
		node1->next = (ht->array)[idx];
	(ht->array)[idx] = node1;

	return (1);
}

/**
 * hash_table_set - function of the prototype
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node1 = NULL;
	char *y;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node1 = (ht->array)[idx];
	while (node1 && (strcmp(key, node1->key) != 0))
		node1 = node1->next;
	if (node1 != NULL)
	{
		y = strdup(value);
		if (!y)
			return (0);
		if (node1->value)
			free(node1->value);
		node1->value = y;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}
