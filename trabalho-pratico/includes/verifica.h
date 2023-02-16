#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Dia de referência para calculo de idades
#define Ddate 9

//Mês de referência para calculo de idades
#define Dmes 10

//Ano de referência para calculo de idades
#define Dano 2022

// Verifica se a string só contêm dígitos
int verifica_id (char *a);

// Verifica se o caractér é um M (masculino) ou um F (feminino)
int verifica_gender(char *a);

// Função que calcula a idade através de uma string que contem uma data
int get_idade(char * bday);

// compara se a primeira data é mais recente que a segunda
int compare_dates(char *a, char *b);

//Compara se o primeiro id é mais recente que o segundo
int compare_id(char *a, char *b);

//Compara se a primeira avaliação é maior que a segunda
int compara_avali(double a, double b);

//Compara se a primeira distância é maior que a segunda
int compara_distance(int x, int y);

//Compara se a string c (que é uma data), está entre as datas s1 e s2
int between_dates(char *s1, char *s2, char *c);

int verifica_status(char *a);

int verifica_carClass (char *a);

int verifica_data(char *a);

int verifica_distance_scoreUser_scoreDriver(char *a);

int verifica_tip(char *a);

int verifica_linha(const char *str);

int get_tam_ficheiro_Users(char *f);

int get_tam_ficheiro_Drivers(char *f);

int get_tam_ficheiro_Rides(char *f);

int countDigit(int n);

int verifica_city(char *a);

int compareFiles(FILE *results, FILE *expected);

int valid_user_line(char **data);

int valid_driver_line(char **data);

int valid_ride_line(char **data);