#include "../includes/file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void delete_array_output(char **array_output)
{
    int i = 0;
    if(array_output == NULL)
    {
        return;
    }
    while(array_output[i] != NULL)
    {
        free(array_output[i]);
        i++;
    }
    free(array_output);
}

char **create_output_line(char *line, char **array, int i)
{
    if (line != NULL)
    {
        int line_size = strlen(line);
        char *output_line = malloc(sizeof(char) * line_size + 1);
        strcpy(output_line, line);
        array[i] = output_line;
        // array[i] = strdup(line);
    }
    return array;
}

char **init_array_output(char **array_output, int size)
{
    array_output = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    while (i <= size)
    {
        array_output[i] = NULL;
        i++;
    }
    return array_output;
}

void create_output_file(int n_command, char **output)
{
    char file_name_buff[100];
    int i = 0;
    sprintf(file_name_buff, "Resultados/command%d_output.txt", n_command);
    FILE *result = fopen(file_name_buff, "w");
    if (output == NULL)
    {
        // fputc('\0', result);
        fclose(result);
        return;
        // return;
    }

    while (output[i] != NULL) //
    {
        // printf("%s\n",output[i]);
        fprintf(result, "%s", output[i]);
        free(output[i]);
        i++;
    }
    free(output);
    fclose(result);
}