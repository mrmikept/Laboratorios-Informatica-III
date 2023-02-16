#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Estrutura para guardas as informações das Rides
typedef struct rides_elem * Rides_Elem;

typedef struct rides_catalog * Rides;

//Aloca espaço para um Array com as informações das Rides 
Rides create_Rides(int x);

void init_Array_Rides(Rides rides_catalog, char *path, char *file_name);

//Adiciona uma ride à estrutura das Rides
Rides add_Rides(Rides catalog, char **data);

//Cria uma ride atraves de uma string do ficheiro 
Rides_Elem init_ride(const char *str);

int search_rides(Rides r, int i);

//Devolve o id de uma ride pelo seu indice
char *get_rides_id_indice(int i, Rides r);

//Devolve a data de uma ride pelo seu indice
char *get_rides_date_indice(int i, Rides r);

//Devolve um condutor de uma ride pelo seu indice
char *get_rides_driver_indice(int i, Rides r);

//Devolve um utilizador de uma ride pelo seu indice
char *get_rides_user_indice(int i, Rides r);

//Devolve uma cidade de uma ride pelo seu indice
char *get_rides_city_indice(int i, Rides r);

//Devolve a distancia de uma ride pelo seu indice
char *get_rides_distance_indice(int i, Rides r);

//Devolve a avaliação do utilizador de uma ride pelo seu indice
char *get_rides_score_user_indice(int i, Rides r);

//Devolve a avaliação de um condutor pelo seu indice
char *get_rides_score_driver_indice(int i, Rides r);

//Devolve a gorjeta de uma ride pelo seu indice
char *get_rides_tip_indice(int i, Rides r);

//Devolve o comentario de uma ride pelo seu indice
char *get_rides_comment_indice(int i, Rides r);

//Recebe uma ride d e devolve o seu id
char *get_Rides_id(Rides_Elem d);

//Recebe uma ride d e devolve a data da viagem
char *get_Rides_date(Rides_Elem d);

//Recebe uma ride d e devolve o seu condutor
char *get_Rides_driver(Rides_Elem d);

//Recebe uma ride d e devolve o utilizador
char *get_Rides_user(Rides_Elem d);

//Recebe uma ride d e devolve a cidade
char *get_Rides_city(Rides_Elem d);

//Recebe uma ride d e devolve a distancia
char *get_Rides_distance(Rides_Elem d);

//Recebe uma ride d e devolve a avaliação do utilizador
char *get_Rides_score_user(Rides_Elem d);

//Recebe uma ride d e devolve a avaliação do condutor
char *get_Rides_score_driver(Rides_Elem d);

//Recebe uma ride d e evolve a gorjeta
char *get_Rides_tip(Rides_Elem d);

//Recebe uma ride d e devolve o comentario
char *get_Rides_comment(Rides_Elem d);

void delete_All_Rides(Rides r);

void delete_Ride(Rides_Elem r);

void dump_rides(Rides r);