#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Estrutura para guardar as informações de um Driver
typedef struct drivers_catalog * Drivers;

// Cria um Driver através de uma linha do ficheiro
Drivers init_driver(char **data);

Drivers get_Driver_copy(Drivers driver);

// Recebe um Driver e devolve o seu id
char *get_Driver_id(Drivers d);

// Recebe um Driver e devolve o seu nome
char *get_Driver_name(Drivers d);

// Recebe um Driver e devolve a sua data de nascimento
char *get_Driver_birth_date(Drivers d);

// Recebe um Driver e devolve o seu genero
char *get_Driver_gender(Drivers d);

// Recebe um Driver e devolve a classe do seu carro
char *get_Driver_car_class(Drivers d);

// Recebe um Driver e devolve a matricula do seu carro
char *get_Driver_license_plate(Drivers d);

// Recebe um Driver e devolve a sua cidade
char *get_Driver_city(Drivers d);

// Recebe um Driver e devolve a data da criação da sua conta
char *get_Driver_account_creation(Drivers d);

// Recebe um Driver e devolve o status da sua conta (Active ou Inactive)
char *get_Driver_account_status(Drivers d);

void delete_Driver(Drivers driver);