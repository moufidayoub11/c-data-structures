#include <stdio.h>
#include "hash_tables.h"

int main() {
    hash_table *ht = create_ht(10);

    // Insert key-value pairs
    set_key(ht, "name", "John Doe");
    set_key(ht, "age", "30");
    set_key(ht, "city", "New York");

    // Retrieve values
    char *name = get_key(ht, "name");
    char *age = get_key(ht, "age");
    char *city = get_key(ht, "city");

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("City: %s\n", city);

    // Delete a key-value pair
    char *deleted_value = delete_key(ht, "city");
    if (deleted_value != NULL) {
        printf("Deleted city: %s\n", deleted_value);
        free(deleted_value); // Free the memory as it's the user's responsibility.
    } else {
        printf("City not found.\n");
    }

    // Cleanup and free memory
    delete_ht(ht);
    free(name);
    free(age);
    free(city);

    return 0;
}
