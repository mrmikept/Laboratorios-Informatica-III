#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Recebe a informação, nº do output, estrutura dos users, estrutura dos drivers, 
// estrutura das rides, estrutura da statistics drivers e a estrutura da statistics users.
// Retorna o output desejado pelos parametros definidos
char **querie_1(char *a, HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, Rides r);

// Recebe a informação, nº do output, estrutura dos drivers e a estrutura da statistics drivers. 
// Retorna o output desejado pelos parametros definidos
char **querie_2(char *a, HTable drivers_catalog, HTable drivers_statistics);

// Recebe a informação, nº do output, estrutura dos users e a estrutura da statistics users.
// Retorna o output desejado pelos parametros definidos
char **querie_3(char *a, HTable users_catalog, HTable users_statistics);

// Recebe a informação, nº do output e a estrutura da Statistics City
// Retorna o output desejado pelos parametros definidos
char **querie_4(char *a, HTable stats_city_catalog);

char **querie_5(char *a, HTable drivers_catalog, Rides cr);

char **querie_6(char *a, Rides cr);

char **querie_7(char *command, HTable drivers_catalog, HTable drivers_statistics);

char **querie_8(char *command, HTable users_catalog, HTable drivers_catalog, Rides r);

char **querie_9(char *command, Rides r);