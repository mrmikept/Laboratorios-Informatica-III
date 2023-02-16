#include "../includes/drivers.h"
#include "../includes/verifica.h"

// Estrutura que recebe toda a informação de um Driver
struct drivers_catalog
{
	char *id;
	char *name;
	char *birth_date;
	char *gender;
	char *car_class;
	char *license_plate;
	char *city;
	char *account_creation;
	char *account_status;
};

// Recebe uma string do ficheiro Drivers.csv e cria um Driver fazendo parsing dessa linha
Drivers init_driver(char **data)
{
	if (valid_driver_line(data))
	{
		Drivers u = (Drivers)malloc(sizeof(struct drivers_catalog));
		u->id = strdup(data[0]);
		u->name = strdup(data[1]);
		u->birth_date = strdup(data[2]);
		u->gender = strdup(data[3]);
		char *car_class = strdup(data[4]);
		if (verifica_carClass(car_class) == 1)
		{
			u->car_class = strdup("green");
		}
		if (verifica_carClass(car_class) == 2)
		{
			u->car_class = strdup("basic");
		}
		if (verifica_carClass(car_class) == 3)
		{
			u->car_class = strdup("premium");
		}
		free(car_class);
		u->license_plate = strdup(data[5]);
		u->city = strdup(data[6]);
		u->account_creation = strdup(data[7]); //
		char *acc_status = strdup(data[8]);
		if (verifica_status(acc_status) == 1)
		{
			u->account_status = strdup("active");
		}
		if (verifica_status(acc_status) == 2)
		{
			u->account_status = strdup("inactive");
		}
		free(acc_status);
		return u;
	}
	return NULL;
}

Drivers get_Driver_copy(Drivers driver)
{
	Drivers copy = malloc(sizeof(struct drivers_catalog));
	copy->id = strdup(driver->id);
	copy->name = strdup(driver->name);
	copy->birth_date = strdup(driver->birth_date);
	copy->gender = strdup(driver->gender);
	copy->car_class = strdup(driver->car_class);
	copy->license_plate = strdup(driver->license_plate);
	copy->city = strdup(driver->city);
	copy->account_creation = strdup(driver->account_creation);
	copy->account_status = strdup(driver->account_status);
	return copy;
}

// Recebe a estrutura dos Drivers e retorna o id de um Driver
char *get_Driver_id(Drivers d)
{
	return strdup(d->id);
}

// Recebe a estrutura dos Drivers e retorna o nome de um Driver
char *get_Driver_name(Drivers d)
{
	return strdup(d->name);
}

// Recebe a estrutura dos Drivers e retorna a data de nascimento de um Driver
char *get_Driver_birth_date(Drivers d)
{
	return strdup(d->birth_date);
}

// Recebe a estrutura dos Drivers e retorna o genero de um Driver
char *get_Driver_gender(Drivers d)
{
	return strdup(d->gender);
}

// Recebe a estrutura dos Drivers e retorna a classe do carro de um Driver
char *get_Driver_car_class(Drivers d)
{
	return strdup(d->car_class);
}

// Recebe a estrutura dos Drivers e retorna a matricula do carro de um Driver
char *get_Driver_license_plate(Drivers d)
{
	return strdup(d->license_plate);
}

// Recebe a estrutura dos Drivers e retorna a cidade de um Driver
char *get_Driver_city(Drivers d)
{
	return strdup(d->city);
}

// Recebe a estrutura dos Drivers e retorna a data da criação da conta de um Driver
char *get_Driver_account_creation(Drivers d)
{
	return strdup(d->account_creation);
}

// Recebe a estrutura dos Drivers e retorna o status de um Driver
char *get_Driver_account_status(Drivers d)
{
	return strdup(d->account_status);
}

void delete_Driver(Drivers driver)
{
	free(driver->id);
	free(driver->name);
	free(driver->birth_date);
	free(driver->gender);
	free(driver->car_class);
	free(driver->license_plate);
	free(driver->city);
	free(driver->account_creation);
	free(driver->account_status);
	free(driver);
}