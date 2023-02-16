#include <unistd.h>
#include "../includes/navegator.h"
#include "../includes/verifica.h"

#define CYN "\x1B[36m"
#define RD "\x1B[31m"
#define YLL "\x1B[33m"
#define BLD "\e[1m"
#define UNDR "\e[4m"
#define RESET "\x1B[0m"

/**
\brief para mudar o texto para azul ciano
*/
#define CYAN printf(CYN)

/**
\brief para mudar o texto para vermelho
*/
#define RED printf(RD)

/**
\brief para voltar a cor do texto "normal"
*/
#define RESET_COLOR printf(RESET)

#define CLEAR system("clear")

#define ESPACOS printf("     ")

int switch_menu();
int switch_queries();

int menu()
{
    CLEAR;

    int escolha;

    printf(RD "███╗   ███╗███████╗███╗   ██╗██╗   ██╗\n");
    printf(RD "████╗ ████║██╔════╝████╗  ██║██║   ██║\n");
    printf(RD "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║\n");
    printf(RD "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║\n");
    printf(RD "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝\n");
    printf(RD "╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ \n");

    RESET_COLOR;

    printf("\n\n");

    printf(BLD "Queries: ");
    RESET_COLOR;
    printf("\"1\"\n");
    printf(BLD "Sair: ");
    RESET_COLOR;
    printf("\"0\"\n\n");
    RESET_COLOR;
    printf("Introduza a sua opcao:\n");
    printf("> ");

    scanf("%d", &escolha);

    return escolha;
}

int queries()
{
    CLEAR;

    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗███████╗███████╗\n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗██║██╔════╝██╔════╝\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝██║█████╗  ███████╗\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗██║██╔══╝  ╚════██║\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║██║███████╗███████║\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝╚══════╝╚══════╝\n");

    RESET_COLOR;
    printf("\n");

    printf(BLD "      1 :" RESET " Listar o resumo de um perfil registado no serviço através do seu identificador/username. \n");
    printf(BLD "\n");
    printf(BLD "      2 :" RESET " Listar os N condutores com maior avaliação média. \n");
    printf(BLD "\n");
    printf(BLD "      3 :" RESET " Listar os N utilizadores com maior distância viajada. \n");
    printf(BLD "\n");
    printf(BLD "      4 :" RESET " Preço médio das viagens numa determinada cidade. \n");
    printf(BLD "\n");
    printf(BLD "      5 :" RESET " Preço médio das viagens num dado intervalo de tempo. \n");
    printf(BLD "\n");
    printf(BLD "      6 :" RESET " Distância média percorrida numa determinada cidade. \n");
    printf(BLD "\n");
    printf(BLD "      7 :" RESET " Top N condutores numa determinada cidade. \n");
    printf(BLD "\n");
    printf(BLD "      8 :" RESET " Listar todas as viagens nas quais o utilizador e o condutor são do mesmo género e têm perfis com X ou mais anos. \n");
    printf(BLD "\n");
    printf(BLD "      9 :" RESET " Listar as viagens nas quais o passageiro deu gorjeta num determinado intervalo de tempo.  \n");
    printf(BLD "\n");

    printf(RD "      Menu: -1 | Sair: 0\n" RESET);

    printf("\n");
    RESET_COLOR;
    printf("\n");
    int escolha;
    printf(BLD CYN "     Escolha a query pretendida" RESET YLL " (1 a 9)" RESET BLD " : " RESET);
    scanf("%d", &escolha);
    return escolha;
}

void image_query_1()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗     ██╗\n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ███║\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ╚██║\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝       ██║\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║        ██║\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝        ╚═╝\n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<ID/Username>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_2()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗    ██████╗ \n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ╚════██╗\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝      █████╔╝\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝      ██╔═══╝ \n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║       ███████╗\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝\n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<N>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_3()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗    ██████╗ \n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ╚════██╗\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝      █████╔╝\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝       ╚═══██╗\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║       ██████╔╝\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝       ╚═════╝ \n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<N>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_4()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗    ██╗  ██╗\n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ██║  ██║\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ███████║\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝      ╚════██║\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║            ██║\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝            ╚═╝\n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<Cidade>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_5()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗    ███████╗\n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ██╔════╝\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ███████╗\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝      ╚════██║\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║       ███████║\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝\n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<Data A> <Data B>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_6()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗     ██████╗ \n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ██╔════╝ \n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ███████╗ \n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝      ██╔═══██╗\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║       ╚██████╔╝\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝        ╚═════╝ \n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<Cidade> <Data A> <Data B>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_7()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗    ███████╗\n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ╚════██║\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝         ██╔╝\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝         ██╔╝ \n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║          ██║  \n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝          ╚═╝  \n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<N> <Cidade>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_8()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗     █████╗ \n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ██╔══██╗\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ╚█████╔╝\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝      ██╔══██╗\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║       ╚█████╔╝\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝        ╚════╝ \n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<Genero> <X>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_query_9()
{
    printf(RD " ██████╗ ██╗   ██╗███████╗██████╗ ██╗   ██╗     █████╗ \n");
    printf(RD "██╔═══██╗██║   ██║██╔════╝██╔══██╗╚██╗ ██╔╝    ██╔══██╗\n");
    printf(RD "██║   ██║██║   ██║█████╗  ██████╔╝ ╚████╔╝     ╚██████║\n");
    printf(RD "██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗  ╚██╔╝       ╚═══██║\n");
    printf(RD "╚██████╔╝╚██████╔╝███████╗██║  ██║   ██║        █████╔╝\n");
    printf(RD " ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝        ╚════╝ \n");

    printf("\n\n");

    printf(BLD CYN "Comando: ");
    RESET_COLOR;
    printf(YLL "<Data A> <Data B>\n\n");
    RESET_COLOR;
    printf("Introduza:\n");
    printf("> ");
}

void image_resultado()
{

    printf("█▀█ █▀▀ █▀ █░█ █░░ ▀█▀ ▄▀█ █▀▄ █▀█\n");
    printf("█▀▄ ██▄ ▄█ █▄█ █▄▄ ░█░ █▀█ █▄▀ █▄█\n");

    printf("\n\n");
}

void printf_deseja(int querie)
{
    printf(CYN "Deseja pesquisar de novo: ");
    RESET_COLOR;
    printf("\"%d\"\n", querie);
    printf(CYN "Deseja voltar para as queries: ");
    RESET_COLOR;
    printf("\"-1\"\n");
    printf(CYN "Deseja voltar para o menu: ");
    RESET_COLOR;
    printf("\"-2\"\n\n");

    printf("Introduza a sua opcao:\n");
    printf("> ");
}

void printf_erro(int querie)
{
    printf(BLD RD "Comando Invalido!\n\n");
    RESET_COLOR;
    printf_deseja(querie);
}

int conta_caracteres(char *c)
{
    char *aux = strdup(c);
    int f = 0, j;
    int count = 0;

    for (j = 0; aux[j] != '\0'; j++)
    {
        int k = aux[j];
        if (k >= 0)
        {
            count++;
        }
        if (k < 0)
        {
            f++;
        }
    }

    free(aux);

    f = f / 2;
    count = count + f;

    return count;
}

void printf_espacos(int quantidade, char *c)
{
    int j, espacos;
    char *aux = strdup(c);
    int n = conta_caracteres(aux);

    espacos = quantidade - n;

    for (j = 0; j < espacos; j++)
    {
        printf(" ");
    }

    free(aux);
}

void printf_espacos_dig(int quantidade, int j)
{
    int x = quantidade - countDigit(j);

    for (int i = 0; i <= x; i++)
        printf(" ");
}

void printf_q2(char **m, int inicio, int fim, int pag)
{
    int i, j = inicio + 1;
    char **copy = m;
    int max1 = 0;
    int max_id = 0;
    int max_driver = 0;
    int aux, aux2;
    char *c;

    image_resultado();

    printf(BLD "Pag.%d\n\n", pag);

    RESET_COLOR;

    for (i = inicio; i < fim; i++)
    {

        aux2 = countDigit(i);
        if (max1 < aux2)
            max1 = aux2;
    }

    for (i = inicio; copy[i] != NULL && i < fim; i++)
    {
        char *test = strdup(copy[i]);
        aux = conta_caracteres(strtok(test, ";"));
        if (max_id < aux)
            max_id = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_driver < aux)
            max_driver = aux;

        free(test);
    }

    for (i = inicio; i < fim && m[i] != NULL; i++)
    {
        char *line = strdup(m[i]);
        printf(BLD "%d. ", j);
        printf_espacos_dig(max1, j);
        RESET_COLOR;
        printf(BLD RD "Id do condutor: ");
        RESET_COLOR;
        c = strtok(line, ";");
        printf("%s", c);
        printf_espacos(max_id, c);
        ESPACOS;
        printf(BLD RD "Nome do condutor: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_driver, c);
        ESPACOS;
        printf(BLD RD "Avaliacao media: ");
        RESET_COLOR;
        c = strtok(NULL, "\n");
        printf("%s\n", c);
        free(line);

        j++;
    }

    printf("\n");
}

void printf_q3(char **m, int inicio, int fim, int pag)
{
    int i, j = inicio + 1;
    char **copy = m;
    int max1 = 0;
    int max_username = 0;
    int max_name = 0;
    int aux, aux2;
    char *c;

    image_resultado();

    printf(BLD "Pag.%d\n\n", pag);

    RESET_COLOR;

    for (i = inicio; i < fim; i++)
    {

        aux2 = countDigit(i);
        if (max1 < aux2)
            max1 = aux2;
    }

    for (i = inicio; copy[i] != NULL && i < fim; i++)
    {
        char *test = strdup(copy[i]);
        aux = conta_caracteres(strtok(test, ";"));
        if (max_username < aux)
            max_username = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_name < aux)
            max_name = aux;

        free(test);
    }

    for (i = inicio; i < fim && m[i] != NULL; i++)
    {
        char *line = strdup(m[i]);
        printf(BLD "%d. ", j);
        printf_espacos_dig(max1, j);
        RESET_COLOR;
        printf(BLD RD "Username: ");
        RESET_COLOR;
        c = strtok(line, ";");
        printf("%s", c);
        printf_espacos(max_username, c);
        ESPACOS;
        printf(BLD RD "Nome do utilizador: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_name, c);
        ESPACOS;
        printf(BLD RD "Distancia total: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, "\n"));
        free(line);

        j++;
    }
    printf("\n");
}

void printf_q7(char **m, int inicio, int fim, int pag)
{
    int i, j = inicio + 1;
    char **copy = m;
    int max1 = 0;
    int max_id = 0;
    int max_name = 0;
    int aux, aux2;
    char *c;

    image_resultado();

    printf(BLD "Pag.%d\n\n", pag);

    RESET_COLOR;

    for (i = inicio; i < fim; i++)
    {

        aux2 = countDigit(i);
        if (max1 < aux2)
            max1 = aux2;
    }

    for (i = inicio; copy[i] != NULL && i < fim; i++)
    {
        char *test = strdup(copy[i]);
        aux = conta_caracteres(strtok(test, ";"));
        if (max_id < aux)
            max_id = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_name < aux)
            max_name = aux;

        free(test);
    }

    for (i = inicio; i < fim && m[i] != NULL; i++)
    {
        char *line = strdup(m[i]);
        printf(BLD "%d. ", j);
        printf_espacos_dig(max1, j);
        RESET_COLOR;
        printf(BLD RD "Id do condutor: ");
        RESET_COLOR;
        c = strtok(line, ";");
        printf("%s", c);
        printf_espacos(max_id, c);
        ESPACOS;
        printf(BLD RD "Nome do condutor: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_name, c);
        ESPACOS;
        printf(BLD RD "Avaliacao media: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, "\n"));
        free(line);

        j++;
    }
    printf("\n\n\n");
}

void printf_q8(char **m, int inicio, int fim, int pag)
{
    int i, j = inicio + 1;
    char **copy = m;
    int max1 = 0;
    int max_id = 0;
    int max_name_driver = 0;
    int max_username = 0;
    int aux, aux2;
    char *c;

    image_resultado();

    printf(BLD "Pag.%d\n\n", pag);

    RESET_COLOR;

    for (i = inicio; i < fim; i++)
    {

        aux2 = countDigit(i);
        if (max1 < aux2)
            max1 = aux2;
    }

    for (i = inicio; copy[i] != NULL && i < fim; i++)
    {
        char *test = strdup(copy[i]);
        aux = conta_caracteres(strtok(test, ";"));
        if (max_id < aux)
            max_id = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_name_driver < aux)
            max_name_driver = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_username < aux)
            max_username = aux;

        free(test);
    }

    for (i = inicio; i < fim && m[i] != NULL; i++)
    {
        char *line = strdup(m[i]);
        printf(BLD "%d. ", j);
        printf_espacos_dig(max1, j);
        RESET_COLOR;
        printf(BLD RD "Id do condutor: ");
        RESET_COLOR;
        c = strtok(line, ";");
        printf("%s", c);
        printf_espacos(max_id, c);
        ESPACOS;
        printf(BLD RD "Nome do driver: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_name_driver, c);
        ESPACOS;
        printf(BLD RD "Username: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_username, c);
        ESPACOS;
        printf(BLD RD "Nome do utilizador: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, "\n"));
        free(line);

        j++;
    }
    printf("\n\n\n");
}

void printf_q9(char **m, int inicio, int fim, int pag)
{
    int i, j = inicio + 1;
    char **copy = m;
    int max1 = 0;
    int max_id_viagem = 0;
    int max_data = 0;
    int max_dist = 0;
    int max_city = 0;
    int aux, aux2;
    char *c;

    image_resultado();

    printf(BLD "Pag.%d\n\n", pag);

    RESET_COLOR;

    for (i = inicio; i < fim; i++)
    {

        aux2 = countDigit(i);
        if (max1 < aux2)
            max1 = aux2;
    }

    for (i = inicio; copy[i] != NULL && i < fim; i++)
    {
        char *test = strdup(copy[i]);
        aux = conta_caracteres(strtok(test, ";"));
        if (max_id_viagem < aux)
            max_id_viagem = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_data < aux)
            max_data = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_dist < aux)
            max_dist = aux;

        aux = conta_caracteres(strtok(NULL, ";"));
        if (max_city < aux)
            max_city = aux;

        free(test);
    }

    for (i = inicio; i < fim && m[i] != NULL; i++)
    {
        char *line = strdup(m[i]);

        printf(BLD "%d. ", j);
        printf_espacos_dig(max1, j);
        RESET_COLOR;
        printf(BLD RD "Id da viagem: ");
        RESET_COLOR;
        c = strtok(line, ";");
        printf("%s", c);
        printf_espacos(max_id_viagem, c);
        ESPACOS;
        printf(BLD RD "Data da viagem: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_data, c);
        ESPACOS;
        printf(BLD RD "Distancia: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_dist, c);
        ESPACOS;
        printf(BLD RD "Cidade: ");
        RESET_COLOR;
        c = strtok(NULL, ";");
        printf("%s", c);
        printf_espacos(max_city, c);
        ESPACOS;
        printf(BLD RD "Valor da gorjeta: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, "\n"));
        free(line);

        j++;
    }
    printf("\n\n\n");
}

int insert_error(int querie)
{
    int opcao;

    CLEAR;

    printf_erro(querie);

    scanf("%d", &opcao);

    while (opcao != querie && opcao != -1 && opcao != -2)
    {
        CLEAR;

        printf_erro(querie);

        scanf("%d", &opcao);
    }

    return opcao;
}

int pagination(char **m, int n, int querie)
{
    int flag = 1;
    int i, max = 10, aux = 0, resto = 0;
    int opcao = 1;
    int pag = 1;
    char *a = malloc(sizeof(char *));

    CLEAR;

    printf(BLD RD "Maximo de linhas por pagina\n");
    RESET_COLOR;
    printf("> ");
    scanf("%d", &max);

    if (n <= max)
    {
        CLEAR;

        flag = 0;

        if (querie == 2)
            printf_q2(m, 0, n, pag);

        if (querie == 3)
            printf_q3(m, 0, n, pag);

        if (querie == 7)
            printf_q7(m, 0, n, pag);

        if (querie == 8)
            printf_q8(m, 0, n, pag);

        if (querie == 9)
            printf_q9(m, 0, n, pag);

        printf("\n");
    }
    else
    {
        CLEAR;

        if (querie == 2)
            printf_q2(m, 0, max, pag);

        if (querie == 3)
            printf_q3(m, 0, max, pag);

        if (querie == 7)
            printf_q7(m, 0, max, pag);

        if (querie == 8)
            printf_q8(m, 0, max, pag);

        if (querie == 9)
            printf_q9(m, 0, max, pag);

        printf(YLL "Avancar: ");
        RESET_COLOR;
        printf("\"+\"\n\n\n");

        printf_deseja(querie);

        aux += max;

        scanf("%s", a);

        if (strcmp(a, "+") == 0 || strcmp(a, "-") == 0)
            opcao = 1;
        else
            opcao = atoi(a);

        if (opcao != querie && opcao != -1 && opcao != -2 && opcao != 1)
            return insert_error(querie);

        while (opcao != querie && opcao != -1 && opcao != -2)
        {

            if (strcmp(a, "+") == 0 && (aux + max) <= n) // 9 = "+"
            {
                CLEAR;

                pag++;

                if (querie == 2)
                    printf_q2(m, aux, aux + max, pag);

                if (querie == 3)
                    printf_q3(m, aux, aux + max, pag);

                if (querie == 7)
                    printf_q7(m, aux, aux + max, pag);

                if (querie == 8)
                    printf_q8(m, aux, aux + max, pag);

                if (querie == 9)
                    printf_q9(m, aux, aux + max, pag);

                if (aux + max == n)
                {
                    printf(YLL "Retroceder: ");
                    RESET_COLOR;
                    printf("\"-\"\n\n\n");
                }
                else
                {
                    printf(YLL "Avancar: ");
                    RESET_COLOR;
                    printf("\"+\"        ");
                    printf(YLL "Retroceder: ");
                    RESET_COLOR;
                    printf("\"-\"\n\n\n");
                }

                printf_deseja(querie);

                aux += max;

                scanf("%s", a);

                if (strcmp(a, "+") == 0 && strcmp(a, "-") == 0)
                    opcao = 1;
                else
                    opcao = atoi(a);
            }
            else
            {
                if (strcmp(a, "-") == 0 && (aux - 10) >= 0 && aux != n && pag != 1) // 8 = "-"
                {
                    CLEAR;

                    pag--;

                    aux -= max;

                    if (querie == 2)
                        printf_q2(m, aux - max, aux, pag);

                    if (querie == 3)
                        printf_q3(m, aux - max, aux, pag);

                    if (querie == 7)
                        printf_q7(m, aux - max, aux, pag);

                    if (querie == 8)
                        printf_q8(m, aux - max, aux, pag);

                    if (querie == 9)
                        printf_q9(m, aux - max, aux, pag);

                    if (aux != max)
                    {
                        printf(YLL "Avancar: ");
                        RESET_COLOR;
                        printf("\"+\"        ");
                        printf(YLL "Retroceder: ");
                        RESET_COLOR;
                        printf("\"-\"\n\n\n");
                    }
                    else
                    {
                        printf(YLL "Avancar: ");
                        RESET_COLOR;
                        printf("\"+\"\n\n\n");
                    }

                    printf_deseja(querie);

                    scanf("%s", a);

                    if (strcmp(a, "+") == 0 && strcmp(a, "-") == 0)
                        opcao = 1;
                    else
                        opcao = atoi(a);
                }
                else
                {
                    if (strcmp(a, "+") == 0 && (aux + max) > n && aux < n)
                    {
                        CLEAR;

                        pag++;

                        resto = aux + max - n;
                        resto = max - resto;

                        if (querie == 2)
                            printf_q2(m, aux, n, pag);

                        if (querie == 3)
                            printf_q3(m, aux, n, pag);

                        if (querie == 7)
                            printf_q7(m, aux, n, pag);

                        if (querie == 8)
                            printf_q8(m, aux, n, pag);

                        if (querie == 9)
                            printf_q9(m, aux, n, pag);

                        printf(YLL "Retroceder: ");
                        RESET_COLOR;
                        printf("\"-\"\n\n\n");

                        printf_deseja(querie);

                        aux = n;

                        scanf("%s", a);

                        if (strcmp(a, "+") == 0 && strcmp(a, "-") == 0)
                            opcao = 1;
                        else
                            opcao = atoi(a);
                    }
                    else
                    {
                        if (strcmp(a, "-") == 0 && aux == n)
                        {
                            CLEAR;

                            pag--;

                            if (resto == 0)
                                resto = max;

                            aux = aux - max + (max - resto);

                            if (querie == 2)
                                printf_q2(m, aux - max, aux, pag);

                            if (querie == 3)
                                printf_q3(m, aux - max, aux, pag);

                            if (querie == 7)
                                printf_q7(m, aux - max, aux, pag);

                            if (querie == 8)
                                printf_q8(m, aux - max, aux, pag);

                            if (querie == 9)
                                printf_q9(m, aux - max, aux, pag);

                            if (aux - max == 0)
                            {
                                printf(YLL "Avancar: ");
                                RESET_COLOR;
                                printf("\"+\"\n\n\n");
                            }
                            else
                            {
                                printf(YLL "Avancar: ");
                                RESET_COLOR;
                                printf("\"+\"        ");
                                printf(YLL "Retroceder: ");
                                RESET_COLOR;
                                printf("\"-\"\n\n\n");
                            }

                            printf_deseja(querie);

                            scanf("%s", a);

                            if (strcmp(a, "+") == 0 && strcmp(a, "-") == 0)
                                opcao = 1;
                            else
                                opcao = atoi(a);
                        }
                        else
                        {
                            CLEAR;

                            printf_erro(querie);

                            scanf("%d", &opcao);
                        }
                    }
                }
            }
        }
    }

    if (flag == 0)
    {
        printf_deseja(querie),

            scanf("%d", &opcao);
    }

    return opcao;
}

int nav_query_1(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;
    int opcao;
    int i = 0;
    char *a = malloc(sizeof(char *));
    char **result = NULL;

    image_query_1();

    scanf("%s", a);

    result = querie_1(a, users_catalog, users_statistics, drivers_catalog, drivers_statistics, rides_catalog);

    CLEAR;

    if (result == NULL)
    {
        printf(BLD RD "Utilizador/Condutor nao existe!\n\n");
        RESET_COLOR;
        printf_deseja(1);

        scanf("%d", &opcao);

        if (opcao == 1)
        {
            nav_query_1(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-2))
        {
            switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }

        return insert_error(1);
    }

    image_resultado();

    while (result[i] != NULL)
    {
        printf(RD BLD "Nome: ");
        RESET_COLOR;
        printf("%s\n", strtok(result[i], ";"));
        printf(RD BLD "Genero: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, ";"));
        printf(RD BLD "Idade: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, ";"));
        printf(RD BLD "Avaliacao media: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, ";"));
        printf(RD BLD "Numero de viagens: ");
        RESET_COLOR;
        printf("%s\n", strtok(NULL, ";"));
        printf(RD BLD "Total gasto: ");
        RESET_COLOR;
        printf("%s\n\n", strtok(NULL, "\0"));

        i++;

        free(result[i]);
    }
    free(result);

    RESET_COLOR;

    printf_deseja(1);

    scanf("%d", &opcao);

    if (opcao == 1)
    {
        nav_query_1(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(1);
        }
    }

    return 0;
}

int nav_query_2(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;

    int n, opcao;
    char *a = malloc(sizeof(char *));
    char **result = NULL;

    image_query_2();

    scanf("%s", a);
    n = atoi(a);

    if (verifica_id(a) == 0)
        return insert_error(2);

    result = querie_2(a, drivers_catalog, drivers_statistics);

    opcao = pagination(result, n, 2);

    if (opcao == 2)
    {
        nav_query_2(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(2);
        }
    }

    return 0;
}

int nav_query_3(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;

    image_query_3();

    int n, opcao;
    char *a = malloc(sizeof(char *));
    char **result = NULL;

    scanf("%s", a);
    n = atoi(a);

    if (verifica_id(a) == 0)
        return insert_error(3);

    result = querie_3(a, users_catalog, users_statistics);

    opcao = pagination(result, n, 3);

    if (opcao == 3)
    {
        nav_query_3(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(3);
        }
    }
    return 0;
}

int nav_query_4(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    char *a = malloc(sizeof(char *));
    char **result;
    int opcao;

    CLEAR;

    image_query_4();

    scanf("%s", a);

    result = querie_4(a, stats_city_catalog);

    CLEAR;

    if (result == NULL)
    {
        printf(BLD RD "A cidade nao existe!\n\n");
        RESET_COLOR;
        printf_deseja(4);

        scanf("%d", &opcao);

        if (opcao == 4)
        {
            nav_query_4(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-2))
        {
            switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        return insert_error(4);
    }

    image_resultado();

    printf(BLD RD "Preco medio = ");
    RESET_COLOR;
    printf("%s\n", result[0]);

    printf_deseja(4);

    scanf("%d", &opcao);

    if (opcao == 4)
    {
        nav_query_4(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(4);
        }
    }

    return 0;
}

int nav_query_5(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    char *a1 = malloc(sizeof(char *));
    char *a2 = malloc(sizeof(char *));
    char *a3 = malloc(sizeof(char *));
    char **result;
    int opcao;

    CLEAR;

    image_query_5();

    scanf("%s", a1);
    scanf("%s", a2);

    if (verifica_data(a1) == 0 || verifica_data(a2) == 0)
        return insert_error(5);

    sprintf(a3, "%s %s", a1, a2);

    result = querie_5(a3, drivers_catalog, rides_catalog);

    CLEAR;

    if (result == NULL)
    {
        printf(BLD RD "Nao existem viagens nesse intervalo de datas!\n\n");
        RESET_COLOR;
        printf_deseja(5);

        scanf("%d", &opcao);

        if (opcao == 5)
        {
            nav_query_5(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-2))
        {
            switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }

        return insert_error(5);
    }

    printf(BLD RD "Distancia media = ");
    RESET_COLOR;
    printf("%s\n", result[0]);

    printf_deseja(5);

    scanf("%d", &opcao);

    if (opcao == 5)
    {
        nav_query_5(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(5);
        }
    }

    return 0;
}

int nav_query_6(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    char *a1 = malloc(sizeof(char *));
    char *a2 = malloc(sizeof(char *));
    char *a3 = malloc(sizeof(char *));
    char *a4 = malloc(sizeof(char *));
    char **result;
    int opcao;

    CLEAR;

    image_query_6();

    scanf("%s", a1);
    scanf("%s", a2);
    scanf("%s", a3);

    if (verifica_city(a1) == 0 || verifica_data(a2) == 0 || verifica_data(a3) == 0 || compare_dates(a2, a3) == 0)
        return insert_error(6);

    sprintf(a4, "%s %s %s", a1, a2, a3);

    result = querie_6(a4, rides_catalog);

    CLEAR;

    if (result == NULL)
    {
        printf(BLD RD "Nao foi percorrida distancia nenhuma nesse intervalo!\n\n");
        RESET_COLOR;
        printf_deseja(6);

        scanf("%d", &opcao);

        if (opcao == 6)
        {
            nav_query_6(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        if (opcao == (-2))
        {
            switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }

        return insert_error(6);
    }

    image_resultado();

    printf(BLD RD "Distancia media = ");
    RESET_COLOR;
    printf("%s\n", result[0]);

    printf_deseja(6);

    scanf("%d", &opcao);

    if (opcao == 6)
    {
        nav_query_6(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(6);
        }
    }

    return 0;
}

int nav_query_7(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;

    int n, opcao;
    char *a1 = malloc(sizeof(char *));
    char *a2 = malloc(sizeof(char *));
    char *a3 = malloc(sizeof(char *));
    char **result = NULL;

    image_query_7();

    scanf("%s", a1);
    scanf("%s", a2);

    n = atoi(a1);

    if (verifica_id(a1) == 0 || verifica_city(a2) == 0)
        return insert_error(7);

    sprintf(a3, "%s %s", a1, a2);

    result = querie_7(a3, drivers_catalog, drivers_statistics);

    opcao = pagination(result, n, 7);

    if (opcao == 7)
    {
        nav_query_7(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(7);
        }
    }

    return 0;
}

int nav_query_8(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;

    char *a1 = malloc(sizeof(char *));
    char *a2 = malloc(sizeof(char *));
    char *a3 = malloc(sizeof(char *));
    char **result = NULL;
    int n = 0, opcao;
    char **line;

    image_query_8();

    scanf("%s", a1);
    scanf("%s", a2);

    if (verifica_gender(a1) == 0 || verifica_id(a2) == 0)
        return insert_error(8);

    sprintf(a3, "%s %s", a1, a2);

    result = querie_8(a3, users_catalog, drivers_catalog, rides_catalog);

    line = result;

    while (line[n] != NULL)
    {
        n++;
    }

    opcao = pagination(result, n, 8);

    if (opcao == 8)
    {
        nav_query_8(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(8);
        }
    }

    return 0;
}

int nav_query_9(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    CLEAR;

    char *a1 = malloc(sizeof(char *));
    char *a2 = malloc(sizeof(char *));
    char *a3 = malloc(sizeof(char *));
    char **result = NULL;
    int n = 0, opcao;
    char **line;

    image_query_9();

    scanf("%s", a1);
    scanf("%s", a2);

    if (verifica_data(a1) == 0 && verifica_data(a2) == 0 || compare_dates(a1, a2) == 0)
        return insert_error(9);

    sprintf(a3, "%s %s", a1, a2);

    result = querie_9(a3, rides_catalog);

    line = result;

    while (line[n] != NULL)
    {
        n++;
    }

    opcao = pagination(result, n, 9);

    if (opcao == 9)
    {
        nav_query_9(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    else
    {
        if (opcao == (-1))
        {
            switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
        }
        else
        {
            if (opcao == (-2))
            {
                switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            }
            else
                opcao = insert_error(9);
        }
    }

    return 0;
}

int switch_menu(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    int escolha;
    int aux = 0;
    escolha = menu();

    if (escolha == 1)
        switch_queries(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    else
    {
        if (escolha == 0)
            return 0;
        else
            switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
    }
    return 0;
}

int switch_queries(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    int escolha;

    escolha = queries();

    while (escolha != 0)
    {
        switch (escolha)
        {
        case (-2):
            escolha = switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case (-1):
            escolha = switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 0:
            return 0;
        case 1:
            escolha = nav_query_1(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 2:
            escolha = nav_query_2(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 3:
            escolha = nav_query_3(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 4:
            escolha = nav_query_4(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 5:
            escolha = nav_query_5(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 6:
            escolha = nav_query_6(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 7:
            escolha = nav_query_7(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 8:
            escolha = nav_query_8(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        case 9:
            escolha = nav_query_9(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);
            break;
        default:
            printf("ocorreu um erro\n");
            return -2;
        }
    }

    return escolha;
}

int navegator(HTable users_catalog, HTable users_statistics, HTable drivers_catalog, HTable drivers_statistics, HTable stats_city_catalog, Rides rides_catalog)
{
    int escolha;

    escolha = switch_menu(users_catalog, users_statistics, drivers_catalog, drivers_statistics, stats_city_catalog, rides_catalog);

    CLEAR;

    printf("Programa Encerrado.\n");

    return 0;
}
