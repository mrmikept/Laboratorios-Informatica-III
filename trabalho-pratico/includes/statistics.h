
typedef struct statistics * Stats;

typedef struct statistics_driver_city * Stat_Drivers_City;

typedef struct statistics_City * Stat_City;

//Calcula o valor de uma viagem atráves da classe do carro e da distancia da viagem
double calculaValorViagem(char *car_class, char *distancia);

Stats get_Stats_copy(Stats stats);

Stat_City get_Stats_City_copy(Stat_City stats);

int get_Stats_nviagens(Stats stats);

double get_Stats_avaliacaoTotal(Stats stats);

double get_Stats_money(Stats stats);

int get_Stats_distancia(Stats stats);

double get_Stats_tips(Stats stats);

char *get_Stats_Date(Stats stats);

//Devolve o total gasto numa cidade da estrutura Stat_City
double get_StatCity_totalGasto(Stat_City ssc);

//Devolve o numero de viagens de uma cidade da estrutra Stat_City
int get_StatCity_nviagens(Stat_City ssc);

double get_StatDriver_city_score_indice(Stats driver_stats, char *city);

Stats add_statistics(Stats stats, char *username, char *avali, char *tips, char *car_class, char *date, char *distancia, char *city, int type);

Stat_City add_Stats_City(Stat_City city_catalog, char *city, char *dist, char *car_class);

void delete_statistic(Stats stats);

void delete_statistic_city(Stat_City stats);

//Aloca memoria para uma HashTable de estatistica de cidades
Stat_City create_StatCity();

// //Inicia uma StatCity
// void init_StatCity(Stat_City sc, Rides r, int tamanhoR, Drivers d, int tamanhoD);

//Adiciona uma cidade à estrutura Stat_City
void add_State_City(Stat_City sc, char *cidade, char *car_class, char *distancia);

//Procura uma cidade na estrutura Stat_City
int search_StatCity(char *i, Stat_City sc);

//Devolve a cidade da estrutura Stat_City
char *get_StatCity_city(Stat_City ssc, char *i);
