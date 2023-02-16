#include "../includes/users.h"
#include "../includes/verifica.h"
#include "../includes/hash.h"

// Estrutura para guardar as informações de um User
struct users_catalog
{
	char *username;
	char *name;
	char *gender;
	char *birth_date;
	char *account_creation;
	char *pay_method;
	char *account_status;
};

// Cria um User através le uma linha do ficheiro
Users init_users(char **data)
{
	if (valid_user_line(data))
	{
		Users u = (Users)malloc(sizeof(struct users_catalog));

		u->username = strdup(data[0]);
		u->name = strdup(data[1]);
		u->gender = strdup(data[2]);
		u->birth_date = strdup(data[3]);
		u->account_creation = strdup(data[4]);
		u->pay_method = strdup(data[5]);
		char *acc_status = strdup(data[6]);
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

Users get_User_copy(Users user)
{
	Users copy = malloc(sizeof(struct users_catalog));
	copy->username = strdup(user->username);
	copy->name = strdup(user->name);
	copy->gender = strdup(user->gender);
	copy->birth_date = strdup(user->birth_date);
	copy->account_creation = strdup(user->account_creation);
	copy->pay_method = strdup(user->pay_method);
	copy->account_status = strdup(user->account_status);
	return copy;
}

// Recebe um User para devolver o seu username
char *get_User_username(Users u)
{
	return strdup(u->username);
}

// Recebe um User para devolver o seu name
char *get_User_name(Users u)
{
	return strdup(u->name);
}

// Recebe um User para devolver o seu gender
char *get_User_gender(Users u)
{
	return strdup(u->gender);
}

// Recebe um User para devolver o seu birth_date
char *get_User_birth_date(Users u)
{
	return strdup(u->birth_date);
}

// Recebe um User para devolver o seu account_creation
char *get_User_account_creation(Users u)
{
	return strdup(u->account_creation);
}

// Recebe um User para devolver o seu pay_method
char *get_User_pay_method(Users u)
{
	return strdup(u->pay_method);
}

// Recebe um User para devolver o seu account_status
char *get_User_account_status(Users u)
{
	return strdup(u->account_status);
}

void delete_User(Users user)
{
	free(user->username);
	free(user->name);
	free(user->gender);
	free(user->birth_date);
	free(user->account_creation);
	free(user->pay_method);
	free(user->account_status);
	free(user);
}