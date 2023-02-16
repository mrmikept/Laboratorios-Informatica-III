#include "../includes/verifica.h"
#include <time.h>
#include <unistd.h>

// Verifica se a string só contêm dígitos
int verifica_id(char *a)
{
    int i;
    if (a[0] == '\0')
        return 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Verifica se o caractér é um M (masculino) ou um F (feminino)
int verifica_gender(char *a)
{

    if (a[0] == 'M' || a[0] == 'F')
        return 1;
    else
        return 0;
}

// Função que calcula a idade através de uma string que contem uma data
int get_idade(char *bday)
{
    int year_diff;

    int dDay = Ddate;
    int dMes = Dmes;
    int dAno = Dano;
    char *aux = strdup(bday);
    int d = atoi(strtok(aux, "/"));
    int m = atoi(strtok(NULL, "/"));
    int a = atoi(strtok(NULL, "/"));
    free(aux);

    if (dDay < d)
    {
        if (dMes == 3)
        {
            if ((dAno % 4 == 0 && dAno % 100 != 0) || (dAno % 400 == 0))
            {
                dDay += 29;
            }

            else
            {
                dDay += 28;
            }
        }
        else if (Dmes == 5 || Dmes == 7 || Dmes == 10 || Dmes == 12)
        {
            dDay += 30;
        }

        else
        {
            dDay += 31;
        }

        dMes = dMes - 1;
    }

    if (dMes < m)
    {
        dMes += 12;
        dAno -= 1;
    }

    year_diff = dAno - a;
    return year_diff;
}

// compara se a primeira data é mais recente que a segunda
int compare_dates(char *a, char *b)
{
    int day_diff, mon_diff, year_diff;

    char *aux1 = strdup(a);
    int d1 = atoi(strtok(aux1, "/"));
    int m1 = atoi(strtok(NULL, "/"));
    int a1 = atoi(strtok(NULL, "/"));

    free(aux1);

    char *aux2 = strdup(b);
    int d2 = atoi(strtok(aux2, "/"));
    int m2 = atoi(strtok(NULL, "/"));
    int a2 = atoi(strtok(NULL, "/"));

    free(aux2);

    if (d2 < d1)
    {
        if (m2 == 3)
        {
            if ((a2 % 4 == 0 && a2 % 100 != 0) || (a2 % 400 == 0))
            {
                d2 += 29;
            }

            else
            {
                d2 += 28;
            }
        }

        else if (m2 == 5 || m2 == 7 || m2 == 10 || m2 == 12)
        {
            d2 += 30;
        }

        else
        {
            d2 += 31;
        }

        m2 = m2 - 1;
    }

    if (m2 < m1)
    {
        m2 += 12;
        a2 -= 1;
    }

    day_diff = d2 - d1;
    mon_diff = m2 - m1;
    year_diff = a2 - a1;

    if (year_diff < 0) // Primeira data mais recente
        return 0;

    if (year_diff == 0)
    {
        if (day_diff > 0) // Segundo data mais recente
            return 1;
        if (day_diff == 0 && mon_diff == 0) // Empate
            return 2;
    }

    return 1; // Segunda data é mais recente
}

// Compara se o primeiro id é mais recente que o segundo
int compare_id(char *a, char *b)
{
    int x = atoi(a);
    int y = atoi(b);

    if (y - x <= 0)
        return 0; // id do primeiro é maior
    return 1;     // id do segundo é maior
}

// Compara se a primeira avaliação é maior que a segunda
int compara_avali(double a, double b)
{
    if (a > b)
        return 1; // 1 se primeira maior
    if (a < b)
        return 0; // 0 se segunda maior
    if (a == b)
        return 2; // 2 se forem iguais

    return (-1);
}

// Compara se a primeira distância é maior que a segunda
int compara_distance(int x, int y)
{
    if (x > y)
        return 1;
    if (x < y)
        return 0;
    return 2;
}

// Compara se a string c (que é uma data), está entre as datas s1 e s2
int between_dates(char *s1, char *s2, char *c)
{

    if (compare_dates(s1, c) != 0 && compare_dates(c, s2) != 0)
        return 1;
    return 0;
}

int verifica_status(char *a)
{

    if (a[0] == 'a' || a[0] == 'A')
    {
        if (a[1] == 'c' || a[1] == 'C')
        {
            if (a[2] == 't' || a[2] == 'T')
            {
                if (a[3] == 'i' || a[3] == 'I')
                {
                    if (a[4] == 'v' || a[4] == 'V')
                    {
                        if (a[5] == 'e' || a[5] == 'E')
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if (a[0] == 'i' || a[0] == 'I')
    {
        if (a[1] == 'n' || a[1] == 'N')
        {
            if (a[2] == 'a' || a[2] == 'A')
            {
                if (a[3] == 'c' || a[3] == 'C')
                {
                    if (a[4] == 't' || a[4] == 'T')
                    {
                        if (a[5] == 'i' || a[5] == 'I')
                        {
                            if (a[6] == 'v' || a[6] == 'V')
                            {
                                if (a[7] == 'e' || a[7] == 'E')
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int verifica_carClass(char *a)
{

    if (a[0] == 'g' || a[0] == 'G')
    {
        if (a[1] == 'r' || a[1] == 'R')
        {
            if (a[2] == 'e' || a[2] == 'E')
            {
                if (a[3] == 'e' || a[3] == 'E')
                {
                    if (a[4] == 'n' || a[4] == 'N')
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    if (a[0] == 'b' || a[0] == 'B')
    {
        if (a[1] == 'a' || a[1] == 'A')
        {
            if (a[2] == 's' || a[2] == 'S')
            {
                if (a[3] == 'i' || a[3] == 'I')
                {
                    if (a[4] == 'c' || a[4] == 'C')
                    {
                        return 2;
                    }
                }
            }
        }
        return 0;
    }
    if (a[0] == 'p' || a[0] == 'P')
    {
        if (a[1] == 'r' || a[1] == 'R')
        {
            if (a[2] == 'e' || a[2] == 'E')
            {
                if (a[3] == 'm' || a[3] == 'M')
                {
                    if (a[4] == 'i' || a[4] == 'I')
                    {
                        if (a[5] == 'u' || a[5] == 'U')
                        {
                            if (a[6] == 'm' || a[6] == 'M')
                            {
                                return 3;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int verifica_data(char *a)
{

    char *aux = strdup(a);
    char *aux2 = strdup(a);
    int count = 0;
    int i;

    for (i = 0; aux[i] != '\0'; i++)
    {
        if (aux[i] == '/')
        {
            count++;
        }
    }

    if (count == 2)
    {

        int b1 = atoi(strtok(aux2, "/"));
        int b2 = atoi(strtok(NULL, "/"));
        int b3 = atoi(strtok(NULL, "/"));

        if (b1 >= 1 && b1 <= 31 && b2 >= 1 && b2 <= 12 && b3 <= 2022)
        {
            free(aux);
            free(aux2);
            return 1;
        }
    }
    free(aux);
    free(aux2);
    return 0;
}

int verifica_distance_scoreUser_scoreDriver(char *a)
{
    char *dist = strdup(a);
    double aux = atof(dist);
    int aux2 = atoi(dist);
    char *aux3 = strdup(a);

    if (verifica_id(aux3) == 1)
    {
        if (aux == aux2)
        {
            if (aux2 > 0)
            {
                free(dist);
                free(aux3);
                return 1;
            }
        }
    }
    free(dist);
    free(aux3);
    return 0;
}

int verifica_tip(char *a)
{

    char *aux = strdup(a);
    double aux2 = atof(aux);
    int i;
    int flag = 0;
    char c;

    if (aux[0] == '\0')
    {
        free(aux);
        return 0;
    }
    for (i = 0; aux[i] != '\0'; i++)
    {
        if ((isalpha(aux[i]) != 0))
        {
            free(aux);
            return 0;
        }
    }
    for (i = 0; aux[i] != '\0'; i++)
    {
        if (ispunct(aux[i]) != 0)
        {
            if (aux[i] == '.')
            {
                flag++;
            }
            else
            {
                free(aux);
                return 0;
            }
        }
    }
    // printf("%d\n", flag);
    //  if (c = strchr (aux), '.'; c != '\0'; c= strchr(aux), '.'){
    //      if (c == '.'){
    //          flag = 1;
    //          break;
    //      }
    //  }
    if (flag > 1 || aux2 <= 0)
    {
        free(aux);
        return 0;
    }
    free(aux);
    return 1;
}

int valid_user_line(char **data)
{
    int count = 0;
    int i = 0;

    while (data[count] != NULL)
    {
        count++;
    }
    if (count != 7)
    {
        return 0;
    }

    if (strlen(data[0]) == 0)
    {
        return 0;
    }

    if (strlen(data[1]) == 0 || verifica_id(data[1]) == 1)
    {
        return 0;
    }

    if (strlen(data[2]) == 0 || verifica_gender(data[2]) == 0)
    {
        return 0;
    }

    if (verifica_data(data[3]) == 0)
    {
        return 0;
    }

    if (verifica_data(data[4]) == 0)
    {
        return 0;
    }

    if (strlen(data[5]) == 0)
    {
        return 0;
    }

    if (verifica_status(data[6]) == 0)
    {
        return 0;
    }
    return 1;
}

int valid_driver_line(char **data)
{
    int count = 0;
    int i = 0;

    while (data[count] != NULL)
    {
        count++;
    }
    if (count != 9)
    {
        return 0;
    }

    if (strlen(data[0]) == 0 || verifica_id(data[0]) == 0)
    {
        return 0;
    }

    if (strlen(data[1]) == 0 || verifica_id(data[1]) == 1)
    {
        return 0;
    }

    if (verifica_data(data[2]) == 0)
    {
        return 0;
    }

    if (strlen(data[3]) == 0 || verifica_gender(data[3]) == 0)
    {
        return 0;
    }

    if (verifica_carClass(data[4]) == 0)
    {
        return 0;
    }

    if (strlen(data[5]) == 0)
    {
        return 0;
    }

    if (strlen(data[6]) == 0)
    {
        return 0;
    }

    if (verifica_data(data[7]) == 0)
    {
        return 0;
    }

    if (verifica_status(data[8]) == 0)
    {
        return 0;
    }
    return 1;
}

int valid_ride_line(char **data)
{
    int count = 0;
    int i = 0;

    while (data[count] != NULL)
    {
        count++;
    }
    if (count < 9 || count > 11)
    {
        return 0;
    }

    if (strlen(data[0]) == 0 || verifica_id(data[0]) == 0)
    {
        return 0;
    }

    if (verifica_data(data[1]) == 0)
    {
        return 0;
    }

    if (strlen(data[2]) == 0 || verifica_id(data[2]) == 0)
    {
        return 0;
    }

    if (strlen(data[3]) == 0)
    {
        return 0;
    }

    if (strlen(data[4]) == 0)
    {
        return 0;
    }

    if (strlen(data[5]) == 0 || verifica_distance_scoreUser_scoreDriver(data[5]) == 0)
    {
        return 0;
    }

    if (verifica_distance_scoreUser_scoreDriver(data[6]) == 0)
    {
        return 0;
    }

    if (verifica_distance_scoreUser_scoreDriver(data[7]) == 0)
    {
        return 0;
    }

    if (verifica_tip(data[8]) == 0)
    {
        return 0;
    }
    return 1;
}

int verifica_linha(const char *str)
{
    char *aux = strdup(str);
    char *aux2 = strdup(str);
    char *aux2_ptr = aux2;
    char *x;
    int count = 0;
    int i = 0;

    for (i = 0; aux[i] != '\0'; i++)
    {
        if (aux[i] == ';')
        {
            count++;
        }
    }
    free(aux);

    if (count == 6)
    {
        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }
        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_id(x) == 1)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_gender(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_data(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_data(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, "\r\n");
        if (verifica_status(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }
        free(aux2_ptr);
        return 1;
    }

    if (count == 8)
    {

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_id(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_id(x) == 1)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_data(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_gender(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_carClass(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_data(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_status(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }
        free(aux2_ptr);
        return 1;
    }

    if (count == 9)
    {

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_id(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_data(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_id(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (strlen(x) == 0 || verifica_distance_scoreUser_scoreDriver(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_distance_scoreUser_scoreDriver(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_distance_scoreUser_scoreDriver(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }

        x = strsep(&aux2, ";");
        if (verifica_tip(x) == 0)
        {
            free(aux2_ptr);
            return 0;
        }
        free(aux2_ptr);
        return 1;
    }
}

int get_tam_ficheiro_Users(char *f)
{
    char buffU[50];
    strcpy(buffU, f);
    int tamanhoU = 0;
    char c;

    char *pathU = strcat(buffU, "/users.csv");

    FILE *exU = fopen(pathU, "r");
    if (!exU)
    {
        printf("ERRO: Caminho invalido: %s\n", pathU);
        return 0;
    }

    for (c = getc(exU); c != EOF; c = getc(exU))
    {
        if (c == '\n')
        {
            tamanhoU++;
        }
    }

    tamanhoU = tamanhoU - 1;
    fclose(exU);

    return tamanhoU;
}

int get_tam_ficheiro_Drivers(char *f)
{
    char buffD[50];
    strcpy(buffD, f);
    char c;
    int tamanhoD = 0;

    char *pathD = strcat(buffD, "/drivers.csv");

    FILE *exD = fopen(pathD, "r");
    if (!exD)
    {
        printf("ERRO: Caminho invalido: %s\n", pathD);
        return 0;
    }

    for (c = getc(exD); c != EOF; c = getc(exD))
    {
        if (c == '\n')
        {
            tamanhoD++;
        }
    }

    tamanhoD = tamanhoD - 1;
    fclose(exD);

    return tamanhoD;
}

int get_tam_ficheiro_Rides(char *f)
{
    char buffR[50];
    strcpy(buffR, f);
    char c;
    int tamanhoR = 0;
    char *pathR = strcat(buffR, "/rides.csv");

    FILE *exR = fopen(pathR, "r");
    if (!exR)
    {
        printf("ERRO: Caminho invalido: %s\n", pathR);
        return 0;
    }

    for (c = getc(exR); c != EOF; c = getc(exR))
    {
        if (c == '\n')
        {
            tamanhoR++;
        }
    }

    tamanhoR = tamanhoR - 1;
    fclose(exR);
    return tamanhoR;
}

int countDigit(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int verifica_city(char *a)
{

    // printf("%s\n", a);

    if (strcmp(a, "Braga") == 0)
    {
        return 1;
    }
    if (strcmp(a, "Porto") == 0)
    {
        return 1;
    }
    if (strcmp(a, "Lisboa") == 0)
    {
        return 1;
    }
    if (strcmp(a, "Setúbal") == 0)
    {
        return 1;
    }
    if (strcmp(a, "Faro") == 0)
    {
        return 1;
    }
    return 0;
}

int compareFiles(FILE *results, FILE *expected)
{
    if (!results)
    {
        printf("Erro ao abrir o results\n");
    }
    if (!expected)
    {
        printf("Erro ao abrir o expecteds\n");
    }

    char r = getc(results);
    char e = getc(expected);

    int f = 1;

    while (r != EOF && e != EOF && f)
    {
        if (r != e)
        {
            f = 0;
        }
        r = getc(results);
        e = getc(expected);
    }

    return f;
}