#include "../includes/hash.h"
#include <unistd.h>

struct hash_elem
{
    KEY key;
    void *catalog;
    char state;
};

typedef struct hash_elem *Hash_Elem;

struct hashT
{
    Hash_Elem table;
    int number_elements;
    int max_size;
};

// https://theartincode.stanis.me/008-djb2/
// djb2 algorithm

// Converte uma KEY para um código hash
unsigned long hash(KEY k)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *(k++)))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

Hash_Elem init_Htable_elem(int size)
{
    Hash_Elem table = malloc(sizeof(struct hash_elem) * size);
    for (int i = 0; i < size; i++)
    {
        table[i].key = NULL;
        table[i].catalog = NULL;
        table[i].state = 0;
    }
    return table;
}

HTable create_Table(int size)
{
    HTable hash_table = malloc(sizeof(struct hashT));
    if (hash_table == NULL)
    {
        printf("Error on malloc of HashTable!\n");
        return NULL;
    }
    hash_table->max_size = size;
    hash_table->number_elements = 0;
    hash_table->table = init_Htable_elem(hash_table->max_size);

    return hash_table;
}

void delete_Htable_Elem(Hash_Elem table, int size)
{
    int i = 0;
    while (i < size)
    {
        if (table[i].state)
        {
            free(table[i].key);
        }
        i++;
    }
    free(table);
}

void delete_Htable(HTable table)
{
    int i = 0;
    while (i < table->max_size)
    {
        if (table->table[i].state)
        {
            free(table->table[i].key);
        }
        i++;
    }
    free(table->table);
    free(table);
}

Hash_Elem rehash_HashT(Hash_Elem new_table, Hash_Elem old_table, int size_old, int size_new)
{
    int i = 0;
    while (i < size_old)
    {
        if (old_table[i].state)
        {
            int key = hash(old_table[i].key) % size_new;
            while (new_table[key].state)
            {
                key = (key + 1) % size_new;
            }
            if (new_table[key].state)
            {
                printf("Cheia\n");
                return new_table;
            }
            else
            {
                new_table[key].key = strdup(old_table[i].key);
                new_table[key].catalog = old_table[i].catalog;
                new_table[key].state = 1;
            }
        }
        i++;
    }
    delete_Htable_Elem(old_table, size_old);
    return new_table;
}

int add_HTable(HTable htable, KEY i, void *element)
{
    if (htable->number_elements >= (htable->max_size * 0.7))
    {
        Hash_Elem new_htable = init_Htable_elem(htable->max_size * 2);
        if (new_htable != NULL)
        {
            htable->table = rehash_HashT(new_htable, htable->table, htable->max_size, htable->max_size * 2);
            htable->max_size *= 2;
        }
        else
        {
            return 1;
        }
    }
    unsigned long key = hash(i) % htable->max_size;
    while (htable->table[key].state && strcmp(htable->table[key].key, i))
    {
        key = (key + 1) % htable->max_size;
    }
    if (htable->table[key].state && strcmp(htable->table[key].key, i) == 0)
    {
        htable->table[key].catalog = element;
        return 0;
    }
    if (htable->table[key].state)
    {
        printf("Cheia\n");
        return 1;
    }
    else
    {
        htable->table[key].key = strdup(i);
        htable->table[key].catalog = element;
        htable->table[key].state = 1;
        htable->number_elements++;
    }
    return 0;
}

int search_HTable(HTable htable, KEY i)
{
    unsigned long key = hash(i) % htable->max_size;
    while (htable->table[key].state && strcmp(htable->table[key].key, i))
    {
        key = (key + 1) % htable->max_size;
    }
    if (htable->table[key].state && strcmp(htable->table[key].key, i) == 0)
    {
        return 1;
    }
    return 0;
}

int search_HTable_index(HTable htable, int i)
{
    if (htable->table[i].state)
    {
        return 1;
    }
    return 0;
}

void *get_HTable_index(HTable catalog, int i)
{
    if (catalog->table[i].state)
    {
        return catalog->table[i].catalog;
    }
    return NULL;
}

void *get_HTable(HTable htable, KEY i)
{
    unsigned long key = hash(i) % htable->max_size;
    while (htable->table[key].state && strcmp(htable->table[key].key, i))
    {
        key = (key + 1) % htable->max_size;
    }
    if (htable->table[key].state && strcmp(htable->table[key].key, i) == 0)
    {
        return htable->table[key].catalog;
    }
    return NULL;
}

void *dump_HTable(HTable htable, int i)
{
    if (htable->table[i].state)
    {
        return htable->table[i].catalog;
    }
    return NULL;
}

int get_HTable_size(HTable htable)
{
    return htable->max_size;
}
