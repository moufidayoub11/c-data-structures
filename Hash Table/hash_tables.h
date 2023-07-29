#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct hash_node
{
    char *key;
    char *value;
    struct hash_node *next;
} hash_node;

typedef struct hash_table
{
    unsigned long int size;
    hash_node **array;
} hash_table;

hash_table *create_ht(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int get_index(const unsigned char *key, unsigned long int size);
int set_key(hash_table *ht, const char *key, const char *value);
char *get_key(hash_table *ht, const char *key);
char *delete_key(hash_table *ht, const char *key);
void delete_ht(hash_table *ht);
void print_ht(hash_table *ht);
void debug_ht(hash_table *ht);

#endif /* HASH_TABLE */
