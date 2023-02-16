#include "../includes/drivers.h"
#include "../includes/hash.h"

void init_HTable_Drivers(HTable drivers_catalog, char *path, char *file_name);

Drivers get_HTable_drivers_catalog(HTable drivers_catalog, KEY i);

Drivers get_HTable_drivers_catalog_index(HTable drivers_catalog, int i);

void delete_HTable_Drivers(HTable drivers_catalog);