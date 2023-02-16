#include "../includes/statistics.h"
#include "../includes/verifica.h"
#include <unistd.h>
#include <math.h>

struct statistics
{
    int n_viagens;          //
    double avaliacao_total; //
    double total_gasto;     //
    int distancia;          //
    double total_tips;      //
    struct statistics_driver_city *cities;
    char *date;
};

struct statistics_driver_city
{
    char *cidade;
    double avaliacao_cidade;
    int n_viagens;
    struct statistics_driver_city *next;
};

// Estrutura para guardar as estatistica de uma Cidade
struct statistics_City
{
    char *cidade;
    int n_viagens;
    int distancia_total;
    double total_gasto;
};


void add_Stat_Drivers_City(Stat_Drivers_City head, char *city, char *avaliacao)
{
    Stat_Drivers_City aux = head;
    Stat_Drivers_City ant;
    while (aux != NULL)
    {
        if (strcmp(aux->cidade, city) == 0)
        {
            aux->n_viagens += 1;
            aux->avaliacao_cidade += strtod(avaliacao, NULL);
            break;
        }
        ant = aux;
        aux = aux->next;
    }

    if (aux == NULL)
    {
        Stat_Drivers_City new_city = malloc(sizeof(struct statistics_driver_city));
        new_city->cidade = strdup(city);
        new_city->n_viagens = 1;
        new_city->avaliacao_cidade = strtod(avaliacao, NULL);
        new_city->next = NULL;
        ant->next = new_city;
    }
}

Stats create_Statistics()
{
    Stats stats = malloc(sizeof(struct statistics));
    stats->avaliacao_total = 0;
    stats->date = NULL;
    stats->distancia = 0;
    stats->n_viagens = 0;
    stats->total_gasto = 0;
    stats->total_tips = 0;
    stats->cities = NULL;
    return stats;
}

// Aloca memoria para uma HashTable de estatistica de cidades
Stat_City create_StatCity()
{
    Stat_City sc = malloc(sizeof(struct statistics_City));
    sc->cidade = NULL;
    sc->distancia_total = 0;
    sc->n_viagens = 0;
    sc->total_gasto = 0;
    return sc;
}

Stats add_statistics(Stats stats, char *username, char *avali, char *tips, char *car_class, char *date, char *distancia, char *city, int type)
{
    if (stats == NULL)
    {
        stats = create_Statistics();
    }

    double ValorViagem = calculaValorViagem(car_class, distancia);
    int dist = atoi(distancia);
    double tip = strtod(tips, NULL);

    stats->n_viagens += 1;
    stats->avaliacao_total += strtod(avali, NULL);
    stats->distancia += dist;
    stats->total_gasto += ValorViagem;
    stats->total_tips += tip;
    if (stats->date != NULL && compare_dates(date, stats->date) == 0)
    {
        free(stats->date);
        stats->date = strdup(date);
    }
    if (stats->date == NULL)
    {
        stats->date = strdup(date);
    }
    if (city != NULL && type == 1)
    {
        if (stats->cities == NULL)
        {
            Stat_Drivers_City sdc = malloc(sizeof(struct statistics_driver_city));
            sdc->cidade = strdup(city); //
            sdc->avaliacao_cidade = strtod(avali, NULL);
            sdc->n_viagens = 1;
            sdc->next = NULL;
            stats->cities = sdc;
        }
        else
        {
            add_Stat_Drivers_City(stats->cities, city, avali);
        }
    }
    return stats;
}

Stat_City get_Stats_City_copy(Stat_City stats)
{
    if (stats == NULL)
    {
        return NULL;
    }
    Stat_City new_stats = malloc(sizeof(struct statistics_City));
    new_stats->cidade = strdup(stats->cidade);
    new_stats->distancia_total = stats->distancia_total;
    new_stats->n_viagens = stats->n_viagens;
    new_stats->total_gasto = stats->total_gasto;
    return new_stats;
}

Stat_City add_Stats_City(Stat_City city_catalog, char *city, char *dist, char *car_class)
{
    if (city_catalog == NULL)
    {
        city_catalog = create_StatCity();
        city_catalog->cidade = strdup(city);
    }
    double ride_value = calculaValorViagem(car_class, dist);

    int distance = atoi(dist);

    city_catalog->n_viagens += 1;

    city_catalog->distancia_total += distance;

    city_catalog->total_gasto += ride_value;

    return city_catalog;
}

Stat_Drivers_City get_Stats_Cities_copy(Stat_Drivers_City statistics_city)
{
    if (statistics_city == NULL)
    {
        return NULL;
    }
    else
    {
        Stat_Drivers_City new_stats_city = malloc(sizeof(struct statistics_driver_city));
        new_stats_city->avaliacao_cidade = statistics_city->avaliacao_cidade;
        new_stats_city->cidade = strdup(statistics_city->cidade);
        new_stats_city->n_viagens = statistics_city->n_viagens;
        new_stats_city->next = get_Stats_Cities_copy(statistics_city->next);
        return new_stats_city;
    }
}

Stats get_Stats_copy(Stats stats)
{
    if (stats == NULL)
    {
        return NULL;
    }
    Stats new_stats = malloc(sizeof(struct statistics));
    new_stats->n_viagens = stats->n_viagens;
    new_stats->avaliacao_total = stats->avaliacao_total;
    new_stats->total_gasto = stats->total_gasto;
    new_stats->distancia = stats->distancia;
    new_stats->total_tips = stats->total_tips;
    new_stats->date = strdup(stats->date);
    if (stats->cities != NULL)
    {
        new_stats->cities = get_Stats_Cities_copy(stats->cities);
    }
    else
    {
        new_stats->cities = NULL;
    }
    return new_stats;
}

// Calcula o valor de uma viagem atráves da classe do carro e da distancia da viagem
double calculaValorViagem(char *car_class, char *distancia)
{

    int d = atoi(distancia);
    double valor = 0;
    if (strcmp(car_class, "basic") == 0)
    {
        valor = 3.25 + (0.62 * d);
    }
    if (strcmp(car_class, "green") == 0)
    {
        valor = 4.00 + (0.79 * d);
    }

    if (strcmp(car_class, "premium") == 0)
    {
        valor = 5.20 + (0.94 * d);
    }
    return valor;
}

// Devolve o numero de viagens de um Utilziador
int get_Stats_nviagens(Stats stats)
{
    return stats->n_viagens;
}

// Devolve a avaliação total de um Utilizador
double get_Stats_avaliacaoTotal(Stats stats)
{
    return stats->avaliacao_total;
}

// Devolve o total auferido de um Utilizador
double get_Stats_money(Stats stats)
{
    return stats->total_gasto;
}

// Devolve a distancia de um User da estrutura
int get_Stats_distancia(Stats stats)
{
    return stats->distancia;
}

double get_Stats_tips(Stats stats)
{
    return stats->total_tips;
}

char *get_Stats_Date(Stats stats)
{
    return strdup(stats->date);
}

void delete_Stat_Driver_cities(Stat_Drivers_City sdc)
{

    Stat_Drivers_City aux;
    while (sdc != NULL)
    {

        aux = sdc;

        sdc = sdc->next;

        free(aux->cidade);

        free(aux);
    }

    // free(sdc);
}

void delete_statistic(Stats stats)
{
    free(stats->date);
    if (stats->cities != NULL)
    {
        delete_Stat_Driver_cities(stats->cities);
    }
    free(stats);
}

void delete_statistic_city(Stat_City stats)
{
    free(stats->cidade);
    free(stats);
}

double get_StatDriver_city_score_indice(Stats driver_stats, char *city)
{
    Stat_Drivers_City stats_driver_cities = driver_stats->cities;
    while (stats_driver_cities != NULL)
    {
        if (strcmp(stats_driver_cities->cidade, city) == 0)
        {
            return stats_driver_cities->avaliacao_cidade / stats_driver_cities->n_viagens;
        }
        stats_driver_cities = stats_driver_cities->next;
    }
    return (-1);
}

// Devolve o total gasto numa cidade da estrutura Stat_City
double get_StatCity_totalGasto(Stat_City ssc)
{
    return ssc->total_gasto;
}

// Devolve o numero de viagens de uma cidade da estrutra Stat_City
int get_StatCity_nviagens(Stat_City ssc)
{
    return ssc->n_viagens;
}