#include "../includes/rides.h"
#include "../includes/verifica.h"
#include "../includes/file.h"
#include "../includes/parser.h"

// Estrutura para guardas as informações das Rides
struct rides_catalog
{
	void **rides;
	int next_index;
	int max_size;
};

struct rides_elem
{
	char *id;
	char *date;
	char *driver;
	char *user;
	char *city;
	char *distance;
	char *score_user;
	char *score_driver;
	char *tip;
	char *comment;
	char state;
};

// Aloca espaço para um Array com as informações das Rides
Rides create_Rides(int size)
{
	Rides rides_catalog = malloc(sizeof(struct rides_catalog));
	rides_catalog->next_index = 0;
	rides_catalog->max_size = size;
	rides_catalog->rides = malloc(sizeof(void *) * rides_catalog->max_size);

	for (int i = 0; i < rides_catalog->max_size; i++)
	{
		rides_catalog->rides[i] = NULL;
	}
	return rides_catalog;
}

void init_Array_Rides(Rides rides_catalog, char *path, char *file_name)
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
		add_Rides(rides_catalog, output);

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

void **update_state(void **rides, int beggining, int last)
{
	for (int i = beggining; i < last; i++)
	{
		rides[i] = NULL;
	}
	return rides;
}

Rides add_Rides(Rides catalog, char **data)
{
	if (valid_ride_line(data))
	{
		if (catalog->next_index >= catalog->max_size - 2)
		{
			catalog->max_size += 500;
			void **temp_ptr = realloc(catalog->rides, (catalog->max_size * sizeof(void *)));
			if (temp_ptr != NULL)
			{
				// printf("rides realloc done, atual max size: %d\n", catalog->max_size);
				temp_ptr = update_state(temp_ptr, catalog->next_index + 2, catalog->max_size);
				catalog->rides = temp_ptr;
			}
			else
			{
				printf("ERROR ON REALLOC RIDES CATALOG\n");
				return NULL;
			}
		}

		int index = catalog->next_index;

		Rides_Elem ride = malloc(sizeof(struct rides_elem));
		ride->id = strdup(data[0]);
		ride->date = strdup(data[1]);
		ride->driver = strdup(data[2]);
		ride->user = strdup(data[3]);
		ride->city = strdup(data[4]);
		ride->distance = strdup(data[5]);
		ride->score_user = strdup(data[6]);
		ride->score_driver = strdup(data[7]);
		ride->tip = strdup(data[8]);
		ride->comment = strdup(data[9]);
		ride->state = 1;
		catalog->rides[catalog->next_index] = ride;
		catalog->next_index++;
	}
	return catalog;
}

// Cria uma ride atraves de uma string do ficheiro
Rides_Elem init_ride(const char *str)
{
	char *aux = strdup(str);
	Rides_Elem u = malloc(sizeof(struct rides_elem));
	u->id = strdup(strtok(aux, ";"));
	u->date = strdup(strtok(NULL, ";"));
	u->driver = strdup(strtok(NULL, ";"));
	u->user = strdup(strtok(NULL, ";"));
	u->city = strdup(strtok(NULL, ";"));
	u->distance = strdup(strtok(NULL, ";"));
	u->score_user = strdup(strtok(NULL, ";"));
	u->score_driver = strdup(strtok(NULL, ";"));
	u->tip = strdup(strtok(NULL, ";"));
	u->comment = strdup(strtok(NULL, ";"));
	free(aux);
	return u;
}

int search_rides(Rides r, int i)
{
	if (r->rides[i] != NULL)
	{
		return 1;
	}
	return 0;
}

// Devolve o id de uma ride pelo seu indice
char *get_rides_id_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->id);
	}
}

// Devolve a data de uma ride pelo seu indice
char *get_rides_date_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->date);
	}
}

// Devolve um condutor de uma ride pelo seu indice
char *get_rides_driver_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->driver);
	}
}

// Devolve um utilizador de uma ride pelo seu indice
char *get_rides_user_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->user);
	}
}

// Devolve uma cidade de uma ride pelo seu indice
char *get_rides_city_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->city);
	}
}

// Devolve a distancia de uma ride pelo seu indice
char *get_rides_distance_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->distance);
	}
}

// Devolve a avaliação do utilizador de uma ride pelo seu indice
char *get_rides_score_user_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->score_user);
	}
}

// Devolve a avaliação de um condutor pelo seu indice
char *get_rides_score_driver_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->score_driver);
	}
}

// Devolve a gorjeta de uma ride pelo seu indice
char *get_rides_tip_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->tip);
	}
}

// Devolve o comentario de uma ride pelo seu indice
char *get_rides_comment_indice(int i, Rides r)
{
	if (search_rides(r, i))
	{
		Rides_Elem temp = r->rides[i];
		return strdup(temp->comment);
	}
}

// Recebe uma ride d e devolve o seu id
char *get_Rides_id(Rides_Elem d)
{
	return strdup(d->id);
}

// Recebe uma ride d e devolve a data da viagem
char *get_Rides_date(Rides_Elem d)
{
	return strdup(d->date);
}

// Recebe uma ride d e devolve o seu condutor
char *get_Rides_driver(Rides_Elem d)
{
	return strdup(d->driver);
}

// Recebe uma ride d e devolve o utilizador
char *get_Rides_user(Rides_Elem d)
{
	return strdup(d->user);
}

// Recebe uma ride d e devolve a cidade
char *get_Rides_city(Rides_Elem d)
{
	return strdup(d->city);
}

// Recebe uma ride d e devolve a distancia
char *get_Rides_distance(Rides_Elem d)
{
	return strdup(d->distance);
}

// Recebe uma ride d e devolve a avaliação do utilizador
char *get_Rides_score_user(Rides_Elem d)
{
	return strdup(d->score_user);
}

// Recebe uma ride d e devolve a avaliação do condutor
char *get_Rides_score_driver(Rides_Elem d)
{
	return strdup(d->score_driver);
}

// Recebe uma ride d e evolve a gorjeta
char *get_Rides_tip(Rides_Elem d)
{
	return strdup(d->tip);
}

// Recebe uma ride d e devolve o comentario
char *get_Rides_comment(Rides_Elem d)
{
	return strdup(d->comment);
}

void dump_rides(Rides r)
{
	int i = 0;
	while (search_rides(r, i))
	{
		printf("%s\n", get_rides_id_indice(i, r));
		printf("%s\n", get_rides_city_indice(i, r));
		i++;
	}
}

void delete_Ride(Rides_Elem r)
{
	free(r->id);
	free(r->date);
	free(r->driver);
	free(r->user);
	free(r->city);
	free(r->distance);
	free(r->score_user);
	free(r->score_driver);
	free(r->tip);
	free(r->comment);
	free(r);
}

void delete_All_Rides(Rides r)
{
	for (int i = 0; i <= r->max_size && search_rides(r, i); i++)
	{
		delete_Ride(r->rides[i]);
	}
	free(r->rides);
	free(r);
}