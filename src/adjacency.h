#ifndef ADJACENCY_MASTER_01
#define ADJACENCY_MASTER_01

#include <stdlib.h>
#include <string.h>

const char **get_qwerty_adjacency_map(void);
char check_for_adjacency(const char **const button_map, const char first_char, const char second_char);

#endif
