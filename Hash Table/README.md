# Hash Table

This sub-folder contains the implementation of a hash table data structure in C.

## Introduction

A hash table, also known as a hash map, is a data structure that stores key-value pairs. It uses a hash function to convert keys into array indices, allowing for efficient retrieval, insertion, and deletion operations. Hash tables provide fast access to data and are commonly used for data caching, associative arrays, and symbol tables.

### Advantages of Hash Tables:

- Fast Access: Hash tables offer constant-time complexity for insertion, retrieval, and deletion operations in the average case.
- Efficient Data Storage: They use memory efficiently, as they only allocate space for occupied array indices.
- Versatile: Hash tables can be used to implement various data structures, such as dictionaries, sets, and caches.

### Disadvantages of Hash Tables:

- Collision Handling: Hash collisions occur when multiple keys map to the same array index, which requires special handling to ensure correct data retrieval.
- Memory Overhead: Hash tables may consume more memory due to potential collision resolution mechanisms and unused array indices.

## Functions

The hash table implementation includes the following functions:

1. `hash_table *create_ht(unsigned long int size)`: Create a new hash table with the given size.

2. `unsigned long int hash_djb2(const unsigned char *str)`: DJB2 hash function for strings.

3. `unsigned long int get_index(const unsigned char *key, unsigned long int size)`: Get the index for a key in the hash table.

4. `int set_key(hash_table *ht, const char *key, const char *value)`: Insert or update a key-value pair in the hash table.

5. `char *get_key(hash_table *ht, const char *key)`: Retrieve the value associated with a given key from the hash table.

6. `char *delete_key(hash_table *ht, const char *key)`: Remove a key-value pair from the hash table.

7. `void delete_ht(hash_table *ht)`: Delete the entire hash table and free associated memory.

8. `void print_ht(hash_table *ht)`: Print the contents of the hash table.

9. `void debug_ht(hash_table *ht)`: Print the contents of the hash table with multiple linked lists separated by index (for debugging purposes).

### Function Descriptions:

- `create_ht`: This function creates a new hash table of the given size and initializes its array of linked lists to NULL.
```c
// Example usage of the create_ht function
unsigned long int size = 10;
hash_table *ht = create_ht(size);
if (ht != NULL) {
    printf("Hash table created successfully with size: %lu\n", size);
} else {
    printf("Failed to create a hash table.\n");
}
```

- `hash_djb2`: The DJB2 hash function is used to generate a hash value for the given string.
```c
// Example usage of the hash_djb2 function
unsigned long int hash_value = hash_djb2((const unsigned char*)"example_key");
```

- `get_index`: This function computes the index for a key in the hash table based on its hash value and the table size.
```c
// Example usage of the get_index function
unsigned long int index = get_index((const unsigned char*)"example_key", ht->size);
```

- `set_key`: Insert or update a key-value pair in the hash table. If the key already exists, the value is updated; otherwise, a new key-value pair is inserted.
```c
// Example usage of the set_key function
set_key(ht, "name", "John Doe");
```

- `get_key`: Retrieve the value associated with a given key from the hash table. If the key is not found, NULL is returned.
```c
// Example usage of the get_key function
char *value = get_key(ht, "name");
if (value != NULL) {
    printf("Value for 'name': %s\n", value);
} else {
    printf("Key not found.\n");
}
```

- `delete_key`: Remove a key-value pair from the hash table and return the associated value. If the key is not found, NULL is returned.
```c
// Example usage of the delete_key function
char *deleted_value = delete_key(ht, "name");
if (deleted_value != NULL) {
    printf("Deleted value: %s\n", deleted_value);
    free(deleted_value); // Free the memory as it's the user's responsibility.
} else {
    printf("Key not found.\n");
}
```

- `delete_ht`: This function deletes the entire hash table and frees the memory allocated for its nodes and arrays.
```c
// Example usage of the delete_ht function
delete_ht(ht);
```

- `print_ht`: Print the contents of the hash table in the format '{'key1': 'value1', 'key2': 'value2', ...}'.
```c
// Example usage of the print_ht function
print_ht(ht);
```

- `debug_ht`: Print the contents of the hash table with multiple linked lists separated by index for debugging purposes.
```c
// Example usage of the debug_ht function
debug_ht(ht);
```

## Usage

To use the Hash Table implementation in your C projects:

1. Include the `hash_tables.h` header in your C source files.

2. Copy the `hash_tables.c` and `hash_tables.h` files into your project directory.

3. Utilize the provided functions to create, manipulate, and print hash tables.

### Code example
`Look at th example main file ;)`

## Contribution

Contributions to this repository are welcome! If you want to contribute, follow the guidelines mentioned in the main README file.

Please ensure that your code adheres to the existing coding style.

## Additional Resources

To learn more about hash tables and hash functions, consider exploring the following resources:

- [Hash Table by GeeksforGeeks](https://www.geeksforgeeks.org/hashing-data-structure/)
- [Hash Table Wikipedia page](https://en.wikipedia.org/wiki/Hash_table)
- [DJB2 Hash Function](http://www.cse.yorku.ca/~oz/hash.html)
