#include "../includes/hash_drivers.h"
#include "../includes/file.h"
#include "../includes/parser.h"

void init_HTable_Drivers(HTable drivers_catalog, char *path, char *file_name)
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
        Drivers driver = init_driver(output);
        if (driver != NULL)
        {
            add_HTable(drivers_catalog, output[0], driver);
        }

        if(output != NULL)
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
    free(file_path);
    fclose(file);
}

Drivers get_HTable_drivers_catalog_index(HTable drivers_catalog, int i)
{
    Drivers driver = get_HTable_index(drivers_catalog, i);
    if (driver != NULL)
    {
        return get_Driver_copy(driver);
    }
    return NULL;
}

Drivers get_HTable_drivers_catalog(HTable drivers_catalog, KEY i)
{
    Drivers driver = get_HTable(drivers_catalog, i);
    if (driver != NULL)
    {
        return get_Driver_copy(driver);
    }
    return NULL;
}

void delete_HTable_Drivers(HTable drivers_catalog)
{
    int size = get_HTable_size(drivers_catalog);
    int i = 0;
    while (i < size)
    {
        Drivers temp = dump_HTable(drivers_catalog, i);
        if (temp != NULL)
        {
            delete_Driver(temp);
        }
        i++;
    }
    delete_Htable(drivers_catalog);
}