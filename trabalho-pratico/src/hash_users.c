#include "../includes/hash_users.h"
#include "../includes/parser.h"
#include "../includes/file.h"

void init_HTable_Users(HTable users_catalog, char *path, char *file_name)
{
    int lenght_path = strlen(path);
    int lenght_file_name = strlen(file_name);
    char *file_path = malloc(sizeof(char) * (lenght_path + lenght_file_name + 1));
    strcpy(file_path, path);
    strcat(file_path, file_name);
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        printf("ERRO: caminho invalido ficheiro users.csv: %s\n", path);
    }

    char **output = NULL;
    char *line = NULL;
    size_t length = 0;
    ssize_t read;

    read = getline(&line, &length, file);
    free(line);
    line = NULL;
    length = 0;

    while ((read = getline(&line, &length, file)) != (-1))
    {
        output = parse_input(line);
        Users user = init_users(output);
        if (user != NULL)
        {
            add_HTable(users_catalog, output[0], user);
        }

        if (output != NULL)
        {
            free(output);
        }
        free(line);
        line = NULL;
        length = 0;
    }

    if (line)
    {
        free(line);
    }

    fclose(file);
    free(file_path);
}

Users get_HTable_Users_catalog_index(HTable users_catalog, int i)
{
    Users user = get_HTable_index(users_catalog, i);
    if (user != NULL)
    {
        return get_User_copy(user);
    }
    return NULL;
}

Users get_HTable_users_catalog(HTable users_catalog, KEY i)
{
    Users user = get_HTable(users_catalog, i);
    return get_User_copy(user);
}

void delete_HTable_Users(HTable users_catalog)
{
    int size = get_HTable_size(users_catalog);
    int i = 0;
    while (i < size)
    {
        Users temp = dump_HTable(users_catalog, i);
        if (temp != NULL)
        {
            delete_User(temp);
        }
        i++;
    }
    delete_Htable(users_catalog);
}