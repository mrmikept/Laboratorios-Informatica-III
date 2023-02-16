#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//Apontador para uma string
typedef char *KEY;

// typedef struct hash_elem * Hash_Elem;

typedef struct hashT * HTable;

HTable create_Table(int size);
void delete_Htable(HTable table);
int add_HTable(HTable htable, KEY i, void *element);
int search_HTable(HTable htable, KEY i);
int search_HTable_index(HTable htable, int i);
void *get_HTable_index(HTable catalog, int i);
void *get_HTable(HTable htable, KEY i);
int get_HTable_size(HTable htable);
void *dump_HTable(HTable htable, int i);
