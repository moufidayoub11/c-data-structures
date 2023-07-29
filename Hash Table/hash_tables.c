#include "hash_tables.h"


/**
 * create_ht - Create a hash table of given size.
 *
 * @size: The size of the hash table.
 *
 * Return: Pointer to the created hash table or NULL if allocation fails
 */
hash_table *create_ht(unsigned long int size)
{
	hash_table *ht = NULL;
	hash_node **nodes = NULL;
	int i;

	ht = malloc(sizeof(hash_table));

	if (!ht)
		return (NULL);

	nodes = malloc(sizeof(hash_node *) * size);
	if (!nodes)
	{
		free(ht);
		return (0);
	}

	for (i = 0; i < size; i++)
		nodes[i] = NULL;

	ht->array = nodes;
	ht->size = size;

	return (ht);
}

/**
 * hash_djb2 - DJB2 hash function for strings.
 *
 * @str: The string to be hashed.
 *
 * Return: The hash value for the given string.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}

/**
 * get_index - Get the index for a key in the hash table.
 *
 * @key: The key for which the index needs to be computed.
 * @size: The size of the hash table.
 *
 * Return: The computed index for the key.
 */
unsigned long int get_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0 || !key || !(*key))
		return (0);

	return (hash_djb2(key) % size);
}

/**
 * set_key - Insert or update a key-value pair in the hash table.
 *
 * @ht: The hash table in which to insert or update the key-value pair.
 * @key: The key to be inserted or updated.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int set_key(hash_table *ht, const char *key, const char *value)
{
	if (!ht || !key || !(*key) || !value)
		return (0);

	unsigned int size = ht->size;
	unsigned int index = get_index((unsigned char *) key, size);
	hash_node *new = NULL;
	hash_node *curr = ht->array[index];

	while (curr && strcmp(curr->key, key) != 0)
		curr = curr->next;

	if (curr)
	{
		free(curr->value);
		curr->value = strdup(value);

		return (1);
	}

	new = malloc(sizeof(hash_node));

	if (!new)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	new->next = ht->array[index];

	ht->array[index] = new;
	return (1);
}

/**
 * get_key - Retrieve the value associated with a given key from the hash table
 *
 * @ht: The hash table from which to retrieve the value.
 * @key: The key whose value needs to be retrieved.
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *get_key(hash_table *ht, const char *key)
{
	if (!ht || !key || !(*key))
		return (NULL);

	unsigned int size = ht->size;
	unsigned int index = get_index((unsigned char *) key, size);
	hash_node *curr = ht->array[index];

	while (curr && strcmp(curr->key, key) != 0)
		curr = curr->next;

	if (curr)
		return (curr->value);

	return (NULL);
}

/**
 * delete_key - Remove a key-value pair from the hash table.
 *
 * @ht: The hash table from which to remove the key-value pair.
 * @key: The key to be removed.
 *
 * Return: The value associated with the removed key
 * or NULL if the key is not found.
 */
char *delete_key(hash_table *ht, const char *key)
{
	if (!ht || !key || !(*key))
		return (NULL);

	unsigned int size = ht->size;
	unsigned int index = get_index((unsigned char *) key, size);
	hash_node *curr = ht->array[index];

	if (!curr)
		return (NULL);

	if (strcmp(curr->key, key) == 0)
	{
		ht->array[index] = curr->next;

		char *value = strdup(curr->value);

		free(curr->key);
		free(curr->value);
		free(curr);

		return (value);
	}

	while (curr->next && strcmp(curr->next->key, key) != 0)
		curr = curr->next;

	hash_node *todelete = curr->next;

	if (todelete)
	{
		char *value = strdup(todelete->value);

		curr->next = todelete->next;
		free(todelete->key);
		free(todelete->value);
		free(todelete);

		return (value);
	}

	return (0);
}

/**
 * delete_ht - Delete the entire hash table and free associated memory.
 *
 * @ht: The hash table to be deleted.
 */
void delete_ht(hash_table *ht)
{
	if (!ht)
		return;

	unsigned int size = ht->size;
	hash_node **array = ht->array;
	int i;

	for (i = 0; i < size; i++)
	{
		hash_node *curr = array[i];
		hash_node *temp;

		while (curr)
		{
			temp = curr->next;

			free(curr->key);
			free(curr->value);
			free(curr);
			curr = temp;
		}
	}

	free(ht->array);
	free(ht);
}

/**
 * print_ht - Print the contents of the hash table.
 *
 * @ht: The hash table to be printed.
 */
void print_ht(hash_table *ht)
{
	if (!ht)
		return;

	unsigned int size = ht->size;
	hash_node **array = ht->array;
	int i;

	printf("{");
	for (i = 0; i < size; i++)
	{
		hash_node *curr = array[i];

		while (curr)
		{
			printf("'%s': '%s'", curr->key, curr->value);
			if (curr->next || i < size - 1)
				printf(", ");
			curr = curr->next;
		}
	}
	printf("}\n");
}


/**
 * debug_ht - Print the contents of the hash table with multiple linked lists
 * seperated by index
 *
 * @ht: The hash table to be printed for debugging purposes.
 */
void debug_ht(hash_table *ht)
{
	if (!ht)
		return;

	unsigned int size = ht->size;
	hash_node **array = ht->array;
	int i;

	for (i = 0; i < size; i++)
	{
		hash_node *curr = array[i];

		printf("(%d): ", i);
		while (curr)
		{
			printf("('%s': '%s')", curr->key, curr->value);
			if (curr->next)
				printf(" -> ");
			curr = curr->next;
		}
		printf("\n");
	}
}
