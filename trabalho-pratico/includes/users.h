#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Estrutura para guardar as informações de um User
typedef struct users_catalog * Users;

Users init_users(char **str);

Users get_User_copy(Users user);

//Recebe um User para devolver o seu username
char *get_User_username(Users s);

//Recebe um User para devolver o seu name
char *get_User_name(Users s);

//Recebe um User para devolver o seu gender
char *get_User_gender(Users s);

//Recebe um User para devolver o seu birth_date
char *get_User_birth_date(Users s);

//Recebe um User para devolver o seu account_creation
char *get_User_account_creation(Users s);

//Recebe um User para devolver o seu pay_method
char *get_User_pay_method(Users s);

//Recebe um User para devolver o seu account_status
char *get_User_account_status(Users s);

int get_size_user(Users u);

void delete_User(Users user);
