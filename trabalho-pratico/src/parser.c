#include "../includes/parser.h"
#include "../includes/file.h"
#include <unistd.h>

char **parse_input(char *line)
{
    int count = 1;
    int i = 0;
    for(i = 0; line[i]; i++)
    {
        if(line[i] == ';')
        {
            count++;
        }
    }

    char **data_line = init_array_output(data_line, count);
    char *data = strtok(line,";");

    i = 0;

    while(data)
    {
        data_line[i++] = data;
        data = strtok(NULL, ";");
    }
    return data_line;
}

// void parser (char *f, HTable users_catalog, HTable drivers_catalog, Rides rides_catalog)
// {
//     char buffU[50];
//     char buffD[50];
//     char buffR[50];
//     strcpy(buffU, f);
//     strcpy(buffD, f);
//     strcpy(buffR, f);

//     char *pathU = strcat(buffU, "/users.csv");
//     char *pathD = strcat(buffD, "/drivers.csv");
//     char *pathR = strcat(buffR, "/rides.csv");

//     FILE *exU = fopen(pathU, "r");
//     if (!exU)
//     {
//         printf("ERRO: Caminho invalido: %s\n", pathU);
//         return;
//     }

//     FILE *exD = fopen(pathD, "r");
//     if (!exD)
//     {
//         printf("ERRO: Caminho invalido: %s\n", pathD);
//         return;
//     }

//     FILE *exR = fopen(pathR, "r");
//     if (!exR)
//     {
//         printf("ERRO: Caminho invalido: %s\n", pathR);
//         return;
//     }

//     int tamanhoU = get_tam_ficheiro_Users(f);
//     int tamanhoD = get_tam_ficheiro_Drivers(f);
//     int tamanhoR = get_tam_ficheiro_Rides(f);

//     char bufferU[200];
//     char bufferD[100];
//     char bufferR[200];
//     char *yU, *yD, *yR;

//     fgets(bufferU, tamanhoU, exU);
//     while (fgets(bufferU, tamanhoU, exU))
//     {
//         char *auxU;
//         auxU = strdup(bufferU);
//         yU = auxU;
//         int i = 0;
//         if (verifica_linha(yU) == 1)
//         {
//             Users s = init_users(yU);                      // Cria um novo user
//             char *username = get_User_username(s);
//             add_HTable(users_catalog, username, s); // Adiciona à estrutura Users
//             i++;
//             free(username);
//         }
//         free(auxU);
//     }
//     fclose(exU);

//     fgets(bufferD, tamanhoD, exD);
//     while (fgets(bufferD, tamanhoD, exD))
//     {
//         char *auxD;
//         auxD = strdup(bufferD);
//         yD = auxD;
//         if (verifica_linha(yD) == 1)
//         {
//             Drivers s = init_driver(yD);           // Cria um novo driver
//             char *id = get_Driver_id(s);
//             add_HTable(drivers_catalog, id, s); // Adiciona à estrutura Drivers
//             free(id);
//         }
//         free(auxD);
//     }
//     fclose(exD);

//     fgets(bufferR, tamanhoR, exR);
//     while (fgets(bufferR, tamanhoR, exR))
//     {
//         char *auxR;
//         auxR = strdup(bufferR);
//         yR = auxR;
//         if (verifica_linha(auxR) == 1)
//         {
//             // Rides_Elem s = init_ride(auxR); // Cria uma nova ride
//             add_Rides(rides_catalog, auxR); // Adiciona à estrutura Rides;

//         }
//         free(auxR);
//     }
//     fclose(exR);
// }
