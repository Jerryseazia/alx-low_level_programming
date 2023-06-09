#include "hash_tables.h"

/**
 * shash_table_create - function of the prototype
 * @size: size
 * Return: pointer to table; NULL if error
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **array;
	unsigned long int x = 0;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}
	while (x < size)
	{
		array[x] = NULL;
		x++;
	}

	ht->size = size;
	ht->array = array;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_to_sorted_list - function of the prototype
 * @ht: sorted hash table
 * @node: node to insert
 * Return: 1 if success, 0 if fail
 */
int insert_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *temp;

	if (!(ht->shead))
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	if (strcmp(node->key, (ht->shead)->key) <= 0) 
	{
		node->snext = ht->shead;
		(ht->shead)->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(node->key, (ht->stail)->key) > 0) 
	{
		node->sprev = ht->stail;
		(ht->stail)->snext = node;
		ht->stail = node;
	}
	else 
	{
		temp = ht->shead;
		while (temp->snext && strcmp(node->key, (temp->snext)->key) > 0)
			temp = temp->snext;
		node->snext = temp->snext;
		node->sprev = temp;
		(temp->snext)->sprev = node;
		temp->snext = node;
	}
	return (1);
}

/**
 * create_and_add_node - function of the prototype
 * @ht: sorted hash table
 * @key: key; can't be empty string
 * @value: value
 * @idx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_and_add_node(shash_table_t *ht, const char *key, const char *value,
			unsigned long int idx)
{
	shash_node_t *node = NULL;
	char *x;
	char *v;
	(void) idx;
	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);

	x = strdup(key);
	if (!x)
	{
		free(node);
		return (0);
	}

	v = strdup(value);
	if (!v)
	{
		free(x);
		free(node);
		return (0);
	}

	node->key = x;
	node->value = v;
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	if ((ht->array)[idx] == NULL)
		node->next = NULL;
	else
		node->next = (ht->array)[idx];
	(ht->array)[idx] = node;

	return (insert_to_sorted_list(ht, node));
}

/**
 * shash_table_set - function of the prototype
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * Return: 1 if success, 0 if fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node = NULL;
	char *y;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		y = strdup(value);
		if (!y)
			return (0);
		if (node->value)
			free(node->value);
		node->value = y;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}

/**
 * shash_table_get - function of the prototype
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *temp;

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

/**
 * shash_table_print - function of the prototype
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma1 = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", comma1, node->key, node->value);
		comma1 = ", ";
		node = node->snext;
	}
	puts("}");
}

/**
 * shash_table_print_rev - function of the prototype
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma1 = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", comma1, node->key, node->value);
		comma1 = ", ";
		node = node->sprev;
	}
	puts("}");
}

/**
 * shash_table_delete - function of the prototype
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int idx = 0;
	shash_node_t *node, *nextnode;

	if (!ht)
		return;

	if (!(ht->array))
	{
		free(ht);
		return;
	}

	while (idx < ht->size)
	{
		node = (ht->array)[idx];
		while (node)
		{
			nextnode = node->next;
			if (node->key)
				free(node->key);
			if (node->value)
				free(node->value);
			node->key = NULL;
			node->value = NULL;
			free(node);
			node = nextnode;
		}
		idx++;
	}
	free(ht->array);
	free(ht);
}
