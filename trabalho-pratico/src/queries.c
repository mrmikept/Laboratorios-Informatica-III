#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "../includes/verifica.h"
#include "../includes/parser.h"
#include "../includes/queries.h"
#include "../includes/drivers.h"
#include "../includes/file.h"
#include "../includes/hash_drivers.h"
#include "../includes/hash_users.h"
#include "../includes/hash_statistics.h"
#include "../includes/file.h"

#include <unistd.h>

// Lista o resumo de um perfil registado no serviço através do seu identificador
// Comando: 1 <ID>
// Output: (Utilizador) : nome;genero;idade;avaliação_media;numero_viagens;total_gasto
//         (Condutor) : nome;genero;idade;avaliação_media;numero_viagens;total_auferido

char **querie_1(char *a, HTable users_catalog, HTable users_statistics_catalog, HTable drivers_catalog, HTable drivers_statistics, Rides r)
{
    char **array_output = NULL;
    int i = (verifica_id(a));
    if (i == 1) // Drivers
    {
        int exist_driver = search_HTable(drivers_catalog, a);
        if (exist_driver == 0) // se a string for vazia escreve no resultado '\0' que é como se fosse vazio
        {
            return NULL;
        }
        else
        {
            Drivers driver = get_HTable_drivers_catalog(drivers_catalog, a);
            char *driver_status = get_Driver_account_status(driver);
            if (driver_status[0] == 'a')
            {
                array_output = init_array_output(array_output, 1);
                KEY driver_name = get_Driver_name(driver);
                KEY driver_gender = get_Driver_gender(driver);
                KEY driver_bday = get_Driver_birth_date(driver);
                int nViagens = 0;
                double total_Auferido = 0.000;
                double avaliacao_Media = 0.000;
                int exist_statis_driver = search_HTable(drivers_statistics, a);
                if (exist_statis_driver)
                {
                    Stats driver_statistics = get_HTable_statistics(drivers_statistics, a);
                    nViagens = get_Stats_nviagens(driver_statistics);
                    total_Auferido = get_Stats_money(driver_statistics) + get_Stats_tips(driver_statistics);
                    avaliacao_Media = get_Stats_avaliacaoTotal(driver_statistics) / nViagens;
                    delete_statistic(driver_statistics);
                }
                char buff[50];
                sprintf(buff, "%s;%s;%d;%.3f;%d;%.3f\n", driver_name, driver_gender, get_idade(driver_bday),
                        avaliacao_Media, nViagens, total_Auferido);
                array_output = create_output_line(buff, array_output, 0);
                free(driver_name);
                free(driver_gender);
                free(driver_bday);
            }
            delete_Driver(driver);
            free(driver_status);
            return array_output;
        }
    }
    else
    {
        int exist_user = search_HTable(users_catalog, a);
        if (!exist_user) // se a string for vazia escreve no resultado '\0' que é como se fosse vazio
        {
            return NULL;
        }
        else
        {
            Users user = get_HTable_users_catalog(users_catalog, a);
            char *user_status = get_User_account_status(user);
            if (user_status[0] == 'a')
            {
                array_output = init_array_output(array_output, 1);

                KEY user_name = get_User_name(user);
                KEY user_gender = get_User_gender(user);
                KEY user_bday = get_User_birth_date(user);
                int exist_statis_user = search_HTable(users_statistics_catalog, a);
                int nViagens = 0;
                double total_Gasto = 0.000;
                double avaliacao_Media = 0.000;
                if (exist_statis_user)
                {
                    Stats user_statistics = get_HTable_statistics(users_statistics_catalog, a);
                    nViagens = get_Stats_nviagens(user_statistics);
                    total_Gasto = get_Stats_money(user_statistics) + get_Stats_tips(user_statistics);
                    avaliacao_Media = get_Stats_avaliacaoTotal(user_statistics) / nViagens;
                    delete_statistic(user_statistics);
                }
                char buff[50];
                sprintf(buff, "%s;%s;%d;%.3f;%d;%.3f\n", user_name, user_gender, get_idade(user_bday),
                        avaliacao_Media, nViagens, total_Gasto);
                array_output = create_output_line(buff, array_output, 0);
                free(user_name);
                free(user_gender);
                free(user_bday);
            }
            delete_User(user);
            free(user_status);
            return array_output;
        }
    }
}

struct q2 // Estrutura usada na Q2
{
    KEY date;
    KEY driver;
    KEY name;
    double avaliacao_media;
    struct q2 *prev;
    struct q2 *next;
};

// Apontador para a estrutura utilizada na Q2
typedef struct q2 *Q2;

void free_nodeQ2(Q2 node)
{
    free(node->date);
    free(node->driver);
    free(node->name);
    free(node);
}

// libera a memória gasta pela lista
void free_LikendQ2(Q2 lista)
{
    Q2 aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free_nodeQ2(aux);
    }
    // free(lista);
}

// Recebe uma lista e verifica o seu tamanho.
// Se o tamanho da lista é maior que o tamanho pretendido, liberta a memoria alocada da lista excedente.
Q2 verificaTamanhoQ2(Q2 lista, int tamanho)
{
    int count = 0;
    Q2 aux = lista;
    Q2 ant = NULL;
    while (aux != NULL && count != tamanho)
    {
        ant = aux;
        aux = aux->next;
        count++;
    }
    if (aux != NULL && count == tamanho)
    {
        ant->next = NULL;
        free_LikendQ2(aux);
    }
    return lista;
}

// Recebe a cabeça de uma Lista, uma posição "atual" da lista, o nodo anterior da lista, um utilizador a ser adicionado, o tamanho máximo da lista e uma variavel de contagem.
// Adiciona na lista a informação caso seja possivel pelos parametros definidos
Q2 add_Q2(Q2 head, Q2 atual, Q2 ant, Q2 user, int tamanho, int count)
{
    if (count == tamanho) // Se a variavel de contagem for igual ao tamanho, liberta a memoria alocada para o utilizador e retorna a cabeça da lista.
    {
        free_nodeQ2(user);
        return verificaTamanhoQ2(head, tamanho);
    }
    if (head == NULL) // Caso onde é o primeiro utilizador adicionado
    {
        return user;
    }
    if (atual == NULL)
    {
        ant->next = user;
        return verificaTamanhoQ2(head, tamanho);
    }
    else
    {
        int compAval = compara_avali(user->avaliacao_media, atual->avaliacao_media);
        if (compAval == 0) // Caso onde a avaliação do atual é maior
        {
            return add_Q2(head, atual->next, atual, user, tamanho, count + 1);
        }
        if (compAval == 1) // Caso onde a avaliação do user é maior
        {
            if (atual == head) // Caso de ter de inserir à cabeça da lista
            {
                user->next = atual;
                return verificaTamanhoQ2(user, tamanho);
            }
            else // Caso de ter de inserir no meio ou fim da lista
            {
                ant->next = user;
                user->next = atual;
                return verificaTamanhoQ2(head, tamanho);
            }
        }
        if (compAval == 2) // Caso de empate
        {
            int compData = compare_dates(atual->date, user->date);

            if (compData == 0) // Caso onde a data do atual é mais recente
            {
                return add_Q2(head, atual->next, atual, user, tamanho, count + 1);
            }
            if (compData == 1) // Caso da viagem do user ser mais recente
            {
                if (atual == head) // Caso de ter de inserir à cabeça da lista
                {
                    user->next = atual;
                    return verificaTamanhoQ2(user, tamanho);
                }
                else // Caso de ter de inserir no meio ou fim da lista
                {
                    ant->next = user;
                    user->next = atual;
                    return verificaTamanhoQ2(head, tamanho);
                }
            }
            if (compData == 2) // Caso de empate
            {
                int compId = compare_id(atual->driver, user->driver);

                if (compId == 0) // Caso onde o id do atual é maior
                {
                    if (atual == head) // Caso de ter de inserir à cabeça da lista
                    {
                        user->next = atual;
                        return verificaTamanhoQ2(user, tamanho);
                    }
                    else
                    {
                        ant->next = user;
                        user->next = atual;
                        return verificaTamanhoQ2(head, tamanho);
                    }
                }
                if (compId == 1) // Caso onde o id do user é maior
                {
                    return add_Q2(head, atual->next, atual, user, tamanho, count + 1);
                }
            }
        }
    }
    return verificaTamanhoQ2(head, tamanho);
}

// Recebe o inicio da lista,o tamanho da lista e o nº do output
// Escreve a lista no output
char **print_LinkedQ2(Q2 lista, int n)
{
    int i = 0;
    char **array_output = NULL;
    array_output = init_array_output(array_output, n + 1);
    Q2 head = lista;
    while (i < n)
    {
        char output[100];
        sprintf(output, "%s;%s;%.3f\n", lista->driver, lista->name, lista->avaliacao_media);
        array_output = create_output_line(output, array_output, i);
        i++;
        lista = lista->next;
    }
    free_LikendQ2(head);
    return array_output;
}

// Recebe a estrutura das statistics drivers, estrutura dos drivers e o indice
// Retorna a estrutura de um driver para a Q2
Q2 init_Q2(Drivers driver, Stats driver_stats)
{
    Q2 user = malloc(sizeof(struct q2)); // Aloca memoria para um nodo de uma lista ligada
    user->driver = get_Driver_id(driver);
    user->name = get_Driver_name(driver);
    user->date = get_Stats_Date(driver_stats);
    user->avaliacao_media = get_Stats_avaliacaoTotal(driver_stats) / get_Stats_nviagens(driver_stats);
    user->next = NULL;
    return user;
}

// Lista dos tops N drivers com maior avaliação média
// Comando: 2 <N>
// Output: id;nome;avaliação_media
//         id;nome;avaliação_media
//         ...
char **querie_2(char *a, HTable drivers_catalog, HTable drivers_statistics)
{
    if (a == NULL)
    {
        return NULL;
    }

    int n = atoi(a);
    Q2 lista = NULL;
    int i = 0;
    int size = get_HTable_size(drivers_catalog);
    while (i < size)
    {
        int exist_driver = search_HTable_index(drivers_catalog, i);
        if (exist_driver)
        {
            Drivers driver_copy = get_HTable_drivers_catalog_index(drivers_catalog, i);
            char *driver_id = get_Driver_id(driver_copy);
            int exist_driver_statistics = search_HTable(drivers_statistics, driver_id);
            if (exist_driver_statistics)
            {
                char *driver_acc_status = get_Driver_account_status(driver_copy);
                if (driver_acc_status[0] == 'a')
                {
                    Stats driver_stats = get_HTable_statistics(drivers_statistics, driver_id);
                    Q2 user = init_Q2(driver_copy, driver_stats);
                    lista = add_Q2(lista, lista, NULL, user, n, 0);
                    delete_statistic(driver_stats);
                }
                free(driver_acc_status);
            }
            free(driver_id);
            delete_Driver(driver_copy);
        }
        i++;
    }
    return print_LinkedQ2(lista, n);
}

struct q3 // Estrutura usada na Q3
{
    KEY date;        // Armazena a data da viagem mais recente
    KEY username;    // Armazena o username do utilizador
    KEY name;        // Armazena o nome do utilizador
    int distance;    // Armazena a distancia viajada pelo utilizador
    struct q3 *next; // Apontador para a próxima lista
};

// Apontador para a estrutura utilizada na Q3
typedef struct q3 *Q3;

void free_nodeQ3(Q3 node)
{
    free(node->date);
    free(node->username);
    free(node->name);
    free(node);
}

// libera a memória alocada por uma lista
void free_LikendQ3(Q3 lista)
{
    Q3 aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free_nodeQ3(aux);
    }
    // free(lista);
}

// Recebe uma lista e verifica o seu tamanho.
// Se o tamanho da lista é maior que o tamanho pretendido, liberta a memoria alocada da lista excedente.
Q3 verificaTamanhoQ3(Q3 lista, int tamanho)
{
    int count = 0;
    Q3 aux = lista;
    Q3 ant = NULL;
    while (aux != NULL && count != tamanho)
    {
        ant = aux;
        aux = aux->next;
        count++;
    }
    if (aux != NULL && count == tamanho)
    {
        ant->next = NULL;
        free_LikendQ3(aux);
    }
    return lista;
}

// Recebe a cabeça de uma Lista, a posião "atual" da lista, o nodo anterior, um condutor a ser adicionado, o tamanho máximo da lista e uma variavel de contagem.
// Adiciona na lista a informação caso seja possivel pelos parametros definidos
Q3 add_Q3(Q3 head, Q3 atual, Q3 ant, Q3 user, int tamanho, int count)
{
    if (count == tamanho) // Se a variavel de contagem for igual ao tamanho, liberta a memoria alocada para o condutor e retorna a cabeça da lista.
    {
        free_nodeQ3(user);
        return head;
    }
    if (head == NULL) // Caso onde é o primeiro utilizador adicionado
    {
        return user;
    }
    if (atual == NULL)
    {
        ant->next = user;
        user->next = NULL;
        return verificaTamanhoQ3(head, tamanho);
    }
    else
    {
        int compDist = compara_distance(user->distance, atual->distance);

        if (compDist == 0) // Caso a distancia do atual seja maior
        {
            return add_Q3(head, atual->next, atual, user, tamanho, count + 1);
        }

        if (compDist == 1) // Caso se a distancia do user seja maior
        {
            if (atual == head) // Caso de ter de inserir à cabeça da lista
            {
                user->next = atual;
                return verificaTamanhoQ3(user, tamanho);
            }
            else // Caso de ter de inserir no meio ou fim da lista
            {
                ant->next = user;
                user->next = atual;
                return verificaTamanhoQ3(head, tamanho);
            }
        }
        if (compDist == 2) // Caso de empate
        {
            int compData = compare_dates(atual->date, user->date);

            if (compData == 0) // Caso onde a viagem do atual é mais recente
            {
                return add_Q3(head, atual->next, atual, user, tamanho, count + 1);
            }
            if (compData == 1) // Caso onde a viagem do user é mais recente
            {
                if (atual == head)
                {
                    user->next = head;
                    return verificaTamanhoQ3(user, tamanho);
                }
                else
                {
                    ant->next = user;
                    user->next = atual;
                    return verificaTamanhoQ3(head, tamanho);
                }
            }
            if (compData == 2) // Caso de empate
            {
                int compUsername = strcmp(atual->username, user->username);
                if (compUsername > 0) // Caso do username do atual ser maior
                {
                    if (atual == head)
                    {
                        user->next = head;
                        return verificaTamanhoQ3(user, tamanho);
                    }
                    else
                    {
                        ant->next = user;
                        user->next = atual;
                        return verificaTamanhoQ3(head, tamanho);
                    }
                }
                if (compUsername < 0) // Caso do username do user ser maior
                {
                    return add_Q3(head, atual->next, atual, user, tamanho, count + 1);
                }
            }
        }
    }
    return verificaTamanhoQ3(head, tamanho);
}

// Recebe a estrutura das statistics users, estrutura dos users e o indice
// Retorna a estrutura de um user para a Q3
Q3 init_Q3(Users user, Stats user_stats)
{
    Q3 node = malloc(sizeof(struct q3));
    node->username = get_User_username(user);
    node->name = get_User_name(user);
    node->date = get_Stats_Date(user_stats);
    node->distance = get_Stats_distancia(user_stats);
    node->next = NULL;
    return node;
}

// Recebe o inicio da lista,o tamanho da lista e o nº do output
// Escreve a lista no output
char **print_LinkedQ3(Q3 lista, int n)
{
    int i = 0;
    char **array_output = NULL;
    array_output = init_array_output(array_output, n + 1);
    Q3 head = lista;
    while (i < n)
    {
        char output[100];
        sprintf(output, "%s;%s;%d\n", lista->username, lista->name, lista->distance);
        array_output = create_output_line(output, array_output, i);
        i++;
        lista = lista->next;
    }
    free_LikendQ3(head);
    return array_output;
}

// Lista dos tops N utilizadores com maior distância viajada
// Comando: 3 <N>
// Output: username;nome;distancia_total
//         username;nome;distancia_total
//         ...
char **querie_3(char *a, HTable users_catalog, HTable users_statistics)
{
    if (a == NULL)
    {
        return NULL;
    }

    int n = atoi(a);
    Q3 lista = NULL;
    int i = 0;
    int size = get_HTable_size(users_catalog);

    while (i < size)
    {
        int exist_user = search_HTable_index(users_catalog, i);
        if (exist_user)
        {
            Users user_copy = get_HTable_Users_catalog_index(users_catalog, i);
            char *username = get_User_username(user_copy);
            int exist_user_statistics = search_HTable(users_statistics, username);
            char *user_acc_status = get_User_account_status(user_copy);
            if (user_acc_status[0] == 'a' && exist_user_statistics)
            {
                Stats user_stats = get_HTable_statistics(users_statistics, username);
                Q3 user = init_Q3(user_copy, user_stats);
                lista = add_Q3(lista, lista, NULL, user, n, 0);
                delete_statistic(user_stats);
            }
            delete_User(user_copy);
            free(user_acc_status);
            free(username);
        }
        i++;
    }
    return print_LinkedQ3(lista, n);
}

// Preço medio de uma determinada cidade sem considerar gorjetas!
// Comando: 4 <Cidade>
// Output: preco_medio
char **querie_4(char *a, HTable stats_city_catalog)
{
    if (a == NULL) // se a string for vazia escreve no output '\0' que é como se fosse vazio
    {
        return NULL;
    }
    int exist_city = search_HTable(stats_city_catalog, a);
    if (!exist_city) // se não encontrar a cidade escreve no output '\0\ que é como se fosse vazio
    {
        return NULL;
    }
    else
    {
        char output[10];
        char **array_output = init_array_output(array_output, 1);
        Stat_City Stats_City_copy = get_HTable_stats_city(stats_city_catalog, a);
        double preco_medio = get_StatCity_totalGasto(Stats_City_copy) / get_StatCity_nviagens(Stats_City_copy); // calcula o preço médio da cidade
        sprintf(output, "%.3f\n", preco_medio);
        array_output = create_output_line(output, array_output, 0); // escreve o resultado no output
        delete_statistic_city(Stats_City_copy);

        return array_output;
    }
}

char **querie_5(char *a, HTable drivers_catalog, Rides cr)
{
    if (a == NULL)
    {
        return NULL;
    }
    int i = 0;
    double pm = 0, pm_final = 0;
    int n_viagens = 0;
    char output[10];

    char **array_output = NULL;

    char *fst_date = strdup(strtok(a, " "));
    char *snd_date = strdup(strtok(NULL, "\0"));

    while (search_rides(cr, i))
    {
        char *date_ride_copy = get_rides_date_indice(i, cr);
        if (between_dates(fst_date, snd_date, date_ride_copy))
        {
            char *driver_ride_copy = get_rides_driver_indice(i, cr);
            Drivers driver_copy = get_HTable_drivers_catalog(drivers_catalog, driver_ride_copy);
            char *car_class_driver_copy = get_Driver_car_class(driver_copy);
            char *distance_ride_copy = get_rides_distance_indice(i, cr);
            if (strcmp(car_class_driver_copy, "basic") == 0)
            {
                pm += 3.25 + (0.62 * (atoi(distance_ride_copy)));
            }
            if (strcmp(car_class_driver_copy, "green") == 0)
            {
                pm += 4 + (0.79 * (atoi(distance_ride_copy)));
            }
            if (strcmp(car_class_driver_copy, "premium") == 0)
            {
                pm += 5.20 + (0.94 * (atoi(distance_ride_copy)));
            }
            n_viagens += 1;
            free(driver_ride_copy);
            free(car_class_driver_copy);
            free(distance_ride_copy);
            delete_Driver(driver_copy);
        }
        free(date_ride_copy);
        i++;
    }
    free(fst_date);
    free(snd_date);

    pm_final = pm / n_viagens;

    if (pm != 0)
    {
        sprintf(output, "%.3lf\n", pm_final);
        array_output = init_array_output(array_output, 1);
        array_output = create_output_line(output, array_output, 0);
        return array_output;
    }

    return NULL;
}

char **querie_6(char *a, Rides cr)
{
    if (a == NULL)
    {
        return NULL;
    }

    int i = 0;
    double dm = 0;
    double dm_final;
    int n_viagens = 0;
    char output[10];
    char **array_output = NULL;

    char *city = strdup(strtok(a, " "));
    char *fst_date = strdup(strtok(NULL, " "));
    char *snd_date = strdup(strtok(NULL, "\0"));

    while (search_rides(cr, i))
    {
        KEY date_ride_copy = get_rides_date_indice(i, cr);
        KEY city_ride_copy = get_rides_city_indice(i, cr);
        if (between_dates(fst_date, snd_date, date_ride_copy) && strcmp(city, city_ride_copy) == 0)
        {
            KEY distance_ride_copy = get_rides_distance_indice(i, cr);
            dm += atoi(distance_ride_copy);
            n_viagens += 1;
            free(distance_ride_copy);
        }
        free(date_ride_copy);
        free(city_ride_copy);
        i++;
    }

    free(city);
    free(fst_date);
    free(snd_date);

    dm_final = dm / n_viagens;

    if (dm != 0)
    {
        sprintf(output, "%.3lf\n", dm_final);
        array_output = init_array_output(array_output, 1);
        array_output = create_output_line(output, array_output, 0);
        return array_output;
    }
    return NULL;
}

// Querie 7

struct q7 // Estrutura usada na Q3
{
    KEY id;          // Armazena o id do condutor
    KEY name;        // Armazena o nome do condutor
    double score;    // Armazena a avaliação do condutor
    struct q7 *next; // Apontador para a próxima lista
};

typedef struct q7 *Q7;

Q7 init_Q7(Drivers driver, Stats driver_stats, double score)
{
    Q7 user = malloc(sizeof(struct q7));
    user->id = get_Driver_id(driver);
    user->name = get_Driver_name(driver);
    user->score = score;
    user->next = NULL;
    return user;
}

void free_nodeQ7(Q7 node)
{
    free(node->id);
    free(node->name);
    free(node);
}

void free_LikendQ7(Q7 lista)
{
    Q7 aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free_nodeQ7(aux);
    }
}

Q7 verificaTamanhoQ7(Q7 lista, int tamanho)
{
    int count = 0;
    Q7 aux = lista;
    Q7 ant = NULL;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->next;
        count++;
    }
    if (aux != NULL && count == tamanho)
    {
        ant->next = NULL;
        free_LikendQ7(aux);
    }
    return lista;
}

Q7 add_Q7(Q7 head, Q7 atual, Q7 ant, Q7 user, int tamanho, int count)
{
    if (count == tamanho) // Se a variavel de contagem for igual ao tamanho, liberta a memoria alocada para o utilizador e retorna a cabeça da lista.
    {
        free_nodeQ7(user);
        return head;
    }
    if (head == NULL) // Caso onde é o primeiro utilizador adicionado
    {
        return user;
    }
    if (atual == NULL)
    {
        ant->next = user;
        return head;
    }
    else
    {
        int compAval = compara_avali(user->score, atual->score);

        if (compAval == 0) // Caso onde a avaliação do atual é maior
        {
            return add_Q7(head, atual->next, atual, user, tamanho, count++);
        }
        if (compAval == 1) // Caso onde a avaliação do user é maior
        {
            if (atual == head) // Caso de ter de inserir à cabeça da lista
            {
                user->next = atual;
                return verificaTamanhoQ7(user, tamanho);
            }
            else // Caso de ter de inserir no meio ou fim da lista
            {
                ant->next = user;
                user->next = atual;
                return verificaTamanhoQ7(head, tamanho);
            }
        }

        if (compAval == 2) // Caso de empate
        {
            int compId = compare_id(atual->id, user->id);

            if (compId == 0) // Caso onde o id do atual é maior
            {
                return add_Q7(head, atual->next, atual, user, tamanho, count + 1);
            }
            if (compId == 1) // Caso onde o id do user é maior
            {
                if (atual == head)
                {
                    user->next = head;
                    return verificaTamanhoQ7(user, tamanho);
                }
                else
                {
                    ant->next = user;
                    user->next = atual;
                    return verificaTamanhoQ7(head, tamanho);
                }
            }
        }
    }
    return verificaTamanhoQ7(head, tamanho);
}

char **print_LinkedQ7(Q7 lista, int n)
{
    int i = 0;
    char **array_output = NULL;
    array_output = init_array_output(array_output, n + 1);
    Q7 head = lista;
    while (i < n)
    {
        char output[100];
        sprintf(output, "%s;%s;%.3f\n", lista->id, lista->name, lista->score);
        array_output = create_output_line(output, array_output, i);
        i++;
        lista = lista->next;
    }
    free_LikendQ7(head);
    return array_output;
}

char **querie_7(char *command, HTable drivers_catalog, HTable drivers_statistics)
{
    if (command == NULL)
    {
        return NULL;
    }

    char *str_n = strdup(strtok(command, " "));
    int n = atoi(str_n);
    free(str_n);
    char *city = strdup(strtok(NULL, "\0"));

    if (verifica_city(city) == 0)
    {
        free(city);
        return NULL;
    }

    int i = 0;
    int size = get_HTable_size(drivers_catalog);

    Q7 lista = NULL;
    while (i < size)
    {
        int exist_driver = search_HTable_index(drivers_catalog, i);

        if (exist_driver)
        {
            Drivers driver_copy = get_HTable_drivers_catalog_index(drivers_catalog, i);
            char *driver_id = get_Driver_id(driver_copy);
            int exist_driver_stats = search_HTable(drivers_statistics, driver_id);
            if (exist_driver_stats)
            {
                char *driver_acc_status = get_Driver_account_status(driver_copy);
                Stats driver_stats = get_HTable_statistics(drivers_statistics, driver_id);
                double score = get_StatDriver_city_score_indice(driver_stats, city);
                if (driver_acc_status[0] == 'a' && score != (-1))
                {
                    Q7 user = init_Q7(driver_copy, driver_stats, score);
                    lista = add_Q7(lista, lista, NULL, user, n, 0);
                }
                delete_statistic(driver_stats);
                free(driver_acc_status);
            }
            free(driver_id);
            delete_Driver(driver_copy);
        }
        i++;
    }

    free(city);
    return print_LinkedQ7(lista, n);
}

struct q8 // Estrutura usada na Q3
{
    KEY id_driver;     // Armazena a data da viagem mais recente
    KEY name_driver;   // Armazena o username do utilizador
    KEY username_user; // Armazena o nome do utilizador
    KEY name_user;     // Armazena a distancia viajada pelo utilizador
    KEY account_creation_driver;
    KEY account_creation_user;
    KEY id_ride;
    struct q8 *next; // Apontador para a próxima lista
};

typedef struct q8 *Q8;

Q8 init_Q8(Users user, Drivers driver, char *id_ride)
{
    Q8 node = malloc(sizeof(struct q8));

    node->id_driver = get_Driver_id(driver);
    node->name_driver = get_Driver_name(driver);
    node->username_user = get_User_username(user);
    node->name_user = get_User_name(user);
    node->account_creation_driver = get_Driver_account_creation(driver);
    node->account_creation_user = get_User_account_creation(user);
    node->id_ride = id_ride;
    node->next = NULL;
    return node;
}

void free_nodeQ8(Q8 node)
{
    free(node->id_driver);
    free(node->name_driver);
    free(node->username_user);
    free(node->name_user);
    free(node->account_creation_driver);
    free(node->account_creation_user);
    free(node->id_ride);
    free(node);
}

void free_LikendQ8(Q8 lista)
{
    Q8 aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free_nodeQ8(aux);
    }
    // free(lista);
}

char **print_LinkedQ8(Q8 lista, int number_of_lines)
{
    int i = 0;
    char **array_output = NULL;
    array_output = init_array_output(array_output, number_of_lines + 1);
    Q8 head = lista;
    while (lista != NULL)
    {
        char output[100];
        sprintf(output, "%s;%s;%s;%s\n", lista->id_driver, lista->name_driver, lista->username_user, lista->name_user);
        array_output = create_output_line(output, array_output, i);
        lista = lista->next;
        i++;
    }
    free_LikendQ8(head);
    return array_output;
}

Q8 add_Q8(Q8 head, Q8 atual, Q8 ant, Q8 user)
{
    if (head == NULL)
    {
        return user;
    }
    if (atual == NULL)
    {
        ant->next = user;
        return head;
    }
    else
    {
        int comp_date_drivers = compare_dates(user->account_creation_driver, atual->account_creation_driver);

        if (comp_date_drivers == 0) // a data do atual é mais antiga
        {
            return add_Q8(head, atual->next, atual, user);
        }
        if (comp_date_drivers == 1) // a data do user é mais antiga.
        {
            if (head == atual) // Caso ter de inserir à cabeça
            {
                user->next = head;
                return user;
            }
            else // Inserir a meio
            {
                ant->next = user;
                user->next = atual;
                return head;
            }
        }
        if (comp_date_drivers == 2) // Caso empate
        {
            int comp_date_user = compare_dates(user->account_creation_user, atual->account_creation_user);

            if (comp_date_user == 0) // Atual mais antigo
            {
                return add_Q8(head, atual->next, atual, user);
            }
            if (comp_date_user == 1) // User mais antigo
            {
                if (head == atual) // Caso ter de inserir à cabeça
                {
                    user->next = head;
                    return user;
                }
                else // Inserir a meio
                {
                    ant->next = user;
                    user->next = atual;
                    return head;
                }
            }
            if (comp_date_user == 2) // Caso empate
            {
                int comp_Id = compare_id(atual->id_ride, user->id_ride);
                {
                    if (comp_Id == 0) // id do atual é maior
                    {
                        if (atual == head)
                        {
                            user->next = head;
                            return user;
                        }
                        else
                        {
                            ant->next = user;
                            user->next = atual;
                            return head;
                        }
                    }
                    else // id do user ẽ maior
                    {
                        if (atual->next == NULL)
                        {
                            atual->next = user;
                            user->next = NULL;
                            return head;
                        }
                        else
                        {
                            return add_Q8(head, atual->next, atual, user);
                        }
                    }
                }
            }
        }
    }
}

char **querie_8(char *command, HTable users_catalog, HTable drivers_catalog, Rides r)
{
    if (command == NULL)
    {
        return NULL;
    }

    char *gender = strdup(strtok(command, " "));
    char *years_str = strdup(strtok(NULL, "\0"));

    int years = atoi(years_str);
    free(years_str);

    int i = 0;
    int number_of_lines = 0;
    Q8 lista = NULL;
    while (search_rides(r, i))
    {
        char *username_user = get_rides_user_indice(i, r);
        char *id_driver = get_rides_driver_indice(i, r);
        Users user_copy = get_HTable_users_catalog(users_catalog, username_user);
        Drivers driver_copy = get_HTable_drivers_catalog(drivers_catalog, id_driver);
        char *acc_status_user = get_User_account_status(user_copy);
        char *acc_status_driver = get_Driver_account_status(driver_copy);
        if (acc_status_user[0] == 'a' && acc_status_driver[0] == 'a')
        {
            KEY gender_user = get_User_gender(user_copy);
            KEY gender_driver = get_Driver_gender(driver_copy);
            KEY account_creation_user = get_User_account_creation(user_copy);
            KEY account_creation_driver = get_Driver_account_creation(driver_copy);
            int account_age_user = get_idade(account_creation_user);
            int account_age_driver = get_idade(account_creation_driver);

            if (!strcmp(gender, gender_user) && !strcmp(gender, gender_driver) &&
                account_age_user >= years && account_age_driver >= years)
            {
                char *id_ride = get_rides_id_indice(i, r);
                Q8 node = init_Q8(user_copy, driver_copy, id_ride);
                lista = add_Q8(lista, lista, NULL, node);
                number_of_lines++;
            }
            free(gender_user);
            free(gender_driver);
            free(account_creation_user);
            free(account_creation_driver);
        }
        free(username_user);
        free(id_driver);
        free(acc_status_user);
        free(acc_status_driver);
        delete_User(user_copy);
        delete_Driver(driver_copy);
        i++;
    }
    free(gender);
    return print_LinkedQ8(lista, number_of_lines);
}

struct q9 // Estrutura usada na Q3
{
    KEY date;        // Armazena a data da viagem mais recente
    KEY id_ride;     // Armazena o username do utilizador
    KEY city;        // Armazena o nome do utilizador
    int distance;    // Armazena a distancia viajada pelo utilizador
    double tip;      // Armazena a tip
    struct q9 *next; // Apontador para a próxima lista
};

typedef struct q9 *Q9;

Q9 init_Q9(Rides r, int i)
{
    Q9 user = malloc(sizeof(struct q9));
    KEY ride_date_copy = get_rides_date_indice(i, r);
    KEY ride_id_copy = get_rides_id_indice(i, r);
    KEY ride_distance_copy = get_rides_distance_indice(i, r);
    KEY ride_city_copy = get_rides_city_indice(i, r);
    KEY ride_tip_copy = get_rides_tip_indice(i, r);

    user->date = ride_date_copy;
    user->id_ride = ride_id_copy;
    user->city = ride_city_copy;
    user->distance = atoi(ride_distance_copy);
    user->tip = strtod(ride_tip_copy, NULL);
    user->next = NULL;

    free(ride_distance_copy);
    free(ride_tip_copy);

    return user;
}

void free_nodeQ9(Q9 node)
{
    free(node->date);
    free(node->id_ride);
    free(node->city);
    free(node);
}

void free_LikendQ9(Q9 lista)
{
    Q9 aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free_nodeQ9(aux);
    }
    // free(lista);
}

char **print_LinkedQ9(Q9 lista, int number_of_lines)
{
    int i = 0;
    char **array_output = NULL;
    array_output = init_array_output(array_output, number_of_lines + 1);
    Q9 head = lista;
    while (lista != NULL)
    {
        char output[100];
        sprintf(output, "%s;%s;%d;%s;%.3f\n", lista->id_ride, lista->date, lista->distance, lista->city, lista->tip);
        array_output = create_output_line(output, array_output, i);
        lista = lista->next;
        i++;
    }
    free_LikendQ9(head);
    return array_output;
}

Q9 add_Q9(Q9 head, Q9 atual, Q9 ant, Q9 ride)
{
    if (head == NULL)
    {
        return ride;
    }
    if (atual == NULL)
    {
        ant->next = ride;
        return head;
    }
    else
    {
        int compDist = compara_distance(ride->distance, atual->distance);

        if (compDist == 0) // Caso da distancia do atual seja maior
        {
            return add_Q9(head, atual->next, atual, ride);
        }
        if (compDist == 1) // Caso a distancia do user seja maior
        {
            if (atual == head)
            {
                ride->next = head;
                return ride;
            }
            else
            {
                ant->next = ride;
                ride->next = atual;
                return head;
            }
        }
        if (compDist == 2) // Caso de empate
        {
            int compDates = compare_dates(atual->date, ride->date);

            if (compDates == 0) // Caso onde a viagem do atual é mais recente
            {
                return add_Q9(head, atual->next, atual, ride);
            }
            if (compDates == 1) // Caso onde a viagem do user é mais recente
            {
                if (head == atual)
                {
                    ride->next = head;
                    return ride;
                }
                else
                {
                    ant->next = ride;
                    ride->next = atual;
                    return head;
                }
            }
            if (compDates == 2) // Caso de empate
            {
                int compId = compare_id(atual->id_ride, ride->id_ride);

                if (compId == 0) // Caso onde o id do atual é maior
                {
                    return add_Q9(head, atual->next, atual, ride);
                }
                else // Caso o id da ride seja maior
                {
                    if (atual == head)
                    {
                        ride->next = head;
                        return ride;
                    }
                    else
                    {
                        ant->next = ride;
                        ride->next = atual;
                        return head;
                    }
                }
            }
        }
    }
}

char **querie_9(char *command, Rides r)
{
    if (command == NULL)
    {
        return NULL;
    }

    char *fst_date = strdup(strtok(command, " "));
    char *snd_date = strdup(strtok(NULL, "\0"));
    int i = 0;
    int number_of_lines = 0;

    Q9 lista = NULL;

    while (search_rides(r, i))
    {
        KEY ride_date = get_rides_date_indice(i, r);
        int comp_date = between_dates(fst_date, snd_date, ride_date);
        KEY ride_tip = get_rides_tip_indice(i, r);
        double comp_tip = strtod(ride_tip, NULL);

        if (comp_tip != 0 && comp_date)
        {
            Q9 user = init_Q9(r, i);
            lista = add_Q9(lista, lista, NULL, user);
            number_of_lines++;
        }
        free(ride_date);
        free(ride_tip);
        i++;
    }
    free(fst_date);
    free(snd_date);
    return print_LinkedQ9(lista, number_of_lines);
}
