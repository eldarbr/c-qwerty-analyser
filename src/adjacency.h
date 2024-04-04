#ifndef ADJACENCY_MASTER_01
#define ADJACENCY_MASTER_01

#include <stdlib.h>

char **get_qwerty_adjacency_map(void);
void free_qwerty_adjacency_map(char **const map);
char check_for_adjacency(char **const button_map, const char first_char, const char second_char);

#endif
