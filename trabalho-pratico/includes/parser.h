#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "../includes/hash.h"
#include "../includes/verifica.h"
#include "../includes/drivers.h"
#include "../includes/users.h"
#include "../includes/rides.h"

char **parser(char *path, char*file_name);
char **parse_input(char *line);

// void parser (char *f, HTable users_catalog, HTable drivers_catalog, Rides rides_catalog);
