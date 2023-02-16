#include "../includes/statistics.h"
#include "../includes/hash.h"
#include "../includes/hash_drivers.h"
#include "../includes/rides.h"


void init_statistics(HTable users_statistics, HTable drivers_statistics, HTable cities_statistics, HTable drivers_catalog, Rides r);
void delete_HTable_Statistics(HTable stats_catalog);
void delete_HTable_Statistics_City(HTable stats_catalog);
Stats get_HTable_statistics_index(HTable catalog, int i);
Stats get_HTable_statistics(HTable catalog, KEY i);
Stat_City get_HTable_stats_city(HTable catalog, KEY i);
