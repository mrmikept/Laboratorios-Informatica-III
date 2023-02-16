#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "../includes/hash.h"
#include "../includes/verifica.h"
#include "../includes/parser.h"
#include "../includes/queries.h"
#include "../includes/file.h"
#include "../includes/hash_drivers.h"
#include "../includes/hash_statistics.h"
#include "../includes/hash_users.h"

int main(int argc, char const *argv[])
{

    clock_t start, end, startP, endP;
    double timeCPU_taken;
    double time_taken;
    char outputname[500];

    int M = 1000000, i = 0;
    char buffer[M], *x, *y, *z;

    startP = clock();

    FILE *ex = fopen(argv[2], "r"); // lê o ficheiro dos inputs/commands
    if (ex == NULL || argv[2] == NULL || argv[1] == NULL || argv[3] == NULL)
    {
        printf("ERRO: Insira uma diretoria para os ficheiros csv, ficheiro com comando das queries e diretoria com os resultados esperados das queries!\n Exemplo:\n > ./programa-principal <caminho ficheiros csv> <caminho ficheiro.txt> <caminho resultados esperados>\n");
        printf("Caminho para os csv inserido: %s\n Caminho para o ficheiro com comando das queries: %s\n Caminho para os resultados esperados inserido: %s\n", argv[1], argv[2], argv[3]);
        return 1;
    }

    mkdir("Resultados/", 0777); // Cria a diretoria Resultados

    char path[30];
    char pathExp[30];
    strcpy(path, argv[1]); // copia o caminho dos ficheiros csv para a variável path
    strcpy(pathExp, argv[3]);

    int tamanhoU = get_tam_ficheiro_Users(path) * 1.3;
    int tamanhoD = get_tam_ficheiro_Drivers(path) * 1.3;
    int tamanhoR = get_tam_ficheiro_Rides(path);

    printf("A criar e iniciar a HashTable do catalogo dos Users...\n");
    start = clock();

    HTable users_catalog = create_Table(1000);
    init_HTable_Users(users_catalog, path, "/users.csv");
    end = clock();
    timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Demorou %f segundos a criar e iniciar a HashTable do catalogo dos Users!\n\n", timeCPU_taken);

    printf("A criar e iniciar a HashTable do catalogo dos Drivers...\n");
    start = clock();
    HTable drivers_catalog = create_Table(1000);
    init_HTable_Drivers(drivers_catalog, path, "/drivers.csv");
    end = clock();
    timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Demorou %f segundos a criar e iniciar a HashTable do catalogo dos Drivers!\n\n", timeCPU_taken);

    printf("A criar e iniciar o Array do catalogo das Rides...\n");
    start = clock();
    Rides rides_catalog = create_Rides(1000);
    init_Array_Rides(rides_catalog, path, "/rides.csv");
    end = clock();
    timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Demorou %f segundos a criar e iniciar o Array do catalogo das Rides!\n\n", timeCPU_taken);

    printf("A criar modulo da estatistica...\n");
    start = clock();
    HTable drivers_statistics = create_Table(1000);
    HTable stats_city_catalog = create_Table(10);
    HTable users_statistics = create_Table(1000);
    init_statistics(users_statistics, drivers_statistics, stats_city_catalog, drivers_catalog, rides_catalog);
    end = clock();
    timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Demorou %f segundos a criar e iniciar o modulo da estatistica!\n\n", timeCPU_taken);

    while (fgets(buffer, M, ex))
    {
        char *aux;
        char **output = NULL;
        i++;
        aux = strdup(buffer); // string toda do ficheiro inputs/commands
        y = aux;
        x = strsep(&y, " \n"); // nº da querie
        z = strsep(&y, "\n");  // informação para a querie

        FILE *results;
        FILE *expected;

        if (ex == NULL)
        {
            printf("erro NULL\n");
            return 1;
        }

        if (!strcmp(x, "1"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_1(z, users_catalog, users_statistics, drivers_catalog, drivers_statistics, rides_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {
                    printf("Passou pelo teste %d da Querie 1\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie1, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie1 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "2"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_2(z, drivers_catalog, drivers_statistics);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 2\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie2, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie2 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "3"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_3(z, users_catalog, users_statistics);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {
                    printf("Passou pelo teste %d da Querie 3\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie3, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie3 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "4"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_4(z, stats_city_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 4\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie4, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie4 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "5"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_5(z, drivers_catalog, rides_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 5\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie5, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie5 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "6"))
        {

            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_6(z, rides_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 6\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie6, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie6 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "7"))
        {
            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_7(z, drivers_catalog, drivers_statistics);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 7\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie7, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie7 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "8"))
        {
            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_8(z, users_catalog, drivers_catalog, rides_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {

                    printf("Passou pelo teste %d da Querie 8\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie8, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie8 falhou no teste: %d\n\n", i);
            }
            // free(pathE);
            fclose(results);
            fclose(expected);
        }
        if (!strcmp(x, "9"))
        {
            char *str1;
            char str2[200];

            str1 = strdup(pathExp);
            sprintf(str2, "command%d_output.txt", i);

            char str3[100];

            int p = 0, j = 0;

            while (str1[p] != '\0')
            {
                str3[j] = str1[p];
                p++;
                j++;
            }

            p = 0;
            while (str2[p] != '\0')
            {
                str3[j] = str2[p];
                p++;
                j++;
            }
            str3[j] = '\0';

            start = clock();

            output = querie_9(z, rides_catalog);
            create_output_file(i, output);

            end = clock();

            sprintf(outputname, "Resultados/command%d_output.txt", i);

            results = fopen(outputname, "r");
            expected = fopen(str3, "r");

            if (compareFiles(results, expected) == 1)
            {

                timeCPU_taken = (((double)(end - start)) / CLOCKS_PER_SEC);

                if (timeCPU_taken < 10)
                {
                    printf("Passou pelo teste %d da Querie 9\n", i);
                    printf("Tempo do CPU em segundos: %f segundos\n\n", timeCPU_taken);
                }
                else
                {
                    printf("Passou no teste %d da Querie9, mas passou do tempo útil de execução: %f\n\n", i, timeCPU_taken);
                }
            }
            else
            {
                printf("A querie9 falhou no teste: %d\n\n", i);
            }
            fclose(results);
            fclose(expected);
        }
        free(aux);
    }

    delete_HTable_Users(users_catalog);
    delete_HTable_Drivers(drivers_catalog);
    delete_HTable_Statistics(users_statistics);
    delete_HTable_Statistics(drivers_statistics);
    delete_HTable_Statistics_City(stats_city_catalog);
    delete_All_Rides(rides_catalog); // libera a memória gasta pela estrutura do Catálogo Rides

    fclose(ex);

    endP = clock();

    timeCPU_taken = (((double)(endP - startP)) / CLOCKS_PER_SEC);

    printf("O programa demorou %f segundos para executar tudo!\n", timeCPU_taken);

    return 0;
}