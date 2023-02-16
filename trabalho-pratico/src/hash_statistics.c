#include "../includes/hash_statistics.h"

void init_statistics(HTable users_statistics, HTable drivers_statistics, HTable cities_statistics, HTable drivers_catalog, Rides r)
{
    int i = 0;

    while (search_rides(r, i))
    {
        char *driver_ride = get_rides_driver_indice(i, r);
        char *username_ride = get_rides_user_indice(i, r);
        char *score_driver = get_rides_score_driver_indice(i, r);
        char *score_user = get_rides_score_user_indice(i, r);
        char *distance = get_rides_distance_indice(i, r);
        char *tip = get_rides_tip_indice(i, r);
        char *date = get_rides_date_indice(i, r);
        char *city = get_rides_city_indice(i, r);

        Stats user_stats = get_HTable(users_statistics, username_ride);
        Stats driver_stats = get_HTable(drivers_statistics, driver_ride);
        Stat_City city_stats = get_HTable(cities_statistics, city);

        Drivers driver_copy = get_HTable_drivers_catalog(drivers_catalog, driver_ride);
        char *car_class = get_Driver_car_class(driver_copy);
        delete_Driver(driver_copy);

        Stats new_stats_user = add_statistics(user_stats, username_ride, score_user, tip, car_class, date, distance, city, 0);
        Stats new_stats_driver = add_statistics(driver_stats, driver_ride, score_driver, tip, car_class, date, distance, city, 1);
        Stat_City new_stats_city = add_Stats_City(city_stats, city, distance, car_class);

        add_HTable(users_statistics, username_ride, new_stats_user);
        add_HTable(drivers_statistics, driver_ride, new_stats_driver);
        add_HTable(cities_statistics, city, new_stats_city);

        free(driver_ride);
        free(username_ride);
        free(score_driver);
        free(score_user);
        free(distance);
        free(tip);
        free(date);
        free(city);
        free(car_class);

        i++;
    }
}

Stats get_HTable_statistics_index(HTable catalog, int i)
{
    Stats temp = get_HTable_index(catalog, i);
    if (temp != NULL)
    {
        return get_Stats_copy(temp);
    }
    return NULL;
}

Stats get_HTable_statistics(HTable catalog, KEY i)
{
    Stats temp = get_HTable(catalog, i);
    if (temp != NULL)
    {
        return get_Stats_copy(temp);
    }
    return NULL;
}

Stat_City get_HTable_stats_city(HTable catalog, KEY i)
{
    Stat_City temp = get_HTable(catalog, i);
    if (temp != NULL)
    {
        return get_Stats_City_copy(temp);
    }
    return NULL;
}

void delete_HTable_Statistics(HTable stats_catalog)
{
    int size = get_HTable_size(stats_catalog);
    int i = 0;
    while (i < size)
    {
        Stats temp = dump_HTable(stats_catalog, i);
        if (temp != NULL)
        {
            delete_statistic(temp);
        }
        i++;
    }
    delete_Htable(stats_catalog);
}

void delete_HTable_Statistics_City(HTable stats_catalog)
{
    int size = get_HTable_size(stats_catalog);
    int i = 0;
    while (i < size)
    {
        Stat_City temp = dump_HTable(stats_catalog, i);
        if (temp != NULL)
        {
            delete_statistic_city(temp);
        }
        i++;
    }
    delete_Htable(stats_catalog);
}