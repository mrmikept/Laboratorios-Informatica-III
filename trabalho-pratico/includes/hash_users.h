#include "../includes/users.h"
#include "../includes/hash.h"

void delete_HTable_Users(HTable users_catalog);
void init_HTable_Users(HTable users_catalog, char *path, char *file_name);
Users get_HTable_users_catalog(HTable users_catalog, KEY i);
Users get_HTable_Users_catalog_index(HTable users_catalog, int i);