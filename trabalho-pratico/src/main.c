#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../includes/hash_users.h"
#include "../includes/hash_drivers.h"
#include "../includes/hash_statistics.h"
#include "../includes/rides.h"
#include "../includes/verifica.h"
#include "../includes/parser.h"
#include "../includes/queries.h"
#include "../includes/navegator.h"
#include "../includes/file.h"

#define NAVEGATOR 1
#define BATCH 0
#define CLEAR system("clear")

int main_batch(FILE *ex, HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    int M = 1000000, i = 0;
    char buffer[M], *x, *y, *z;

    while (fgets(buffer, M, ex))
    {
        char *aux;
        char **output = NULL;
        i++;
        aux = strdup(buffer); // string toda do ficheiro inputs/commands
        y = aux;
        x = strsep(&y, " \n"); // nº da querie
        z = strsep(&y, "\n");  // informação para a querie

        if (ex == NULL)
        {
            printf("erro NULL\n");
            return 1;
        }
        if (!strcmp(x, "1"))
        {
            output = querie_1(z, users_catalog, users_statistics, drivers_catalog, drivers_statistics, rides_catalog);
        }
        if (!strcmp(x, "2"))
        {
            output = querie_2(z, drivers_catalog, drivers_statistics);
        }
        if (!strcmp(x, "3"))
        {
            output = querie_3(z, users_catalog, users_statistics);
        }
        if (!strcmp(x, "4"))
        {
            output = querie_4(z, stats_city_catalog);
        }
        if (!strcmp(x, "5"))
        {
            output = querie_5(z, drivers_catalog, rides_catalog);
        }
        if (!strcmp(x, "6"))
        {
            output = querie_6(z, rides_catalog);
        }
        if (!strcmp(x, "7"))
        {
            output = querie_7(z, drivers_catalog, drivers_statistics);
        }
        if (!strcmp(x, "8"))
        {
            output = querie_8(z, users_catalog, drivers_catalog, rides_catalog);
        }
        if (!strcmp(x, "9"))
        {
            output = querie_9(z, rides_catalog);
        }

        create_output_file(i, output);

        free(aux);
    }
    
    fclose(ex);

    return 0;
}

int main_navegator(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    navegator(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);

    return 0;
}

int main(int argc, char const *argv[])
{
    int mode = -1;
    FILE *ex;
    char path[30];
    if (argv[1] == NULL) // navegador, sem argumentos
    {
        CLEAR;

        printf("Introduza o caminho para os datasets (Exemplo: \"Datasets/regular/\"): ");
        scanf("%s", path);

        CLEAR;

        printf("A carregar, por favor aguarde ...\n");

        mode = NAVEGATOR;
    }
    else // testes automáticos, 2 argumentos
    {
        if (argv[2] == NULL)
        {
            printf("ERRO: Insira uma diretoria para os ficheiros csv e ficheiro com comando das queries!\n Exemplo:\n > ./programa-principal <caminho ficheiros csv> <caminho ficheiro.txt>\n");
            printf("Caminho para os csv inserio: %s\n Caminho para o ficheiro com comando das queries: %s\n", argv[1], argv[2]);
            return 1;
        }

        strcpy(path, argv[1]);    // copia o caminho dos ficheiros csv para a variável path
        ex = fopen(argv[2], "r"); // lê o ficheiro dos inputs/commands

        if (ex == NULL)
        {
            printf("ERRO: Não foi possivel abrir o ficheiro de testes!\n Exemplo:\n > ./programa-principal <caminho ficheiros csv> <caminho ficheiro.txt>\n");
            return 1;
        }
        mkdir("Resultados/", 0777); // Cria a diretoria Resultados
        mode = BATCH;
    }

    HTable users_catalog = create_Table(1000);
    init_HTable_Users(users_catalog, path, "/users.csv");
    HTable drivers_catalog = create_Table(1000);
    init_HTable_Drivers(drivers_catalog, path, "/drivers.csv");
    Rides rides_catalog = create_Rides(1000);
    init_Array_Rides(rides_catalog, path, "/rides.csv");

    HTable users_statistics = create_Table(1000);
    HTable drivers_statistics = create_Table(1000);
    HTable stats_city_catalog = create_Table(10);
    init_statistics(users_statistics, drivers_statistics, stats_city_catalog, drivers_catalog, rides_catalog);

    if (mode == NAVEGATOR)
    {
        main_navegator(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else if (mode == BATCH)
    {
        main_batch(ex, users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }

    delete_HTable_Users(users_catalog);
    delete_HTable_Drivers(drivers_catalog);
    delete_HTable_Statistics(users_statistics);
    delete_HTable_Statistics(drivers_statistics);
    delete_HTable_Statistics_City(stats_city_catalog);
    delete_All_Rides(rides_catalog); // libera a memória gasta pela estrutura do Catálogo Rides

    return 0;
}
