#include "adjacency.h"

#include "string.h"

char **get_qwerty_adjacency_map() {
    char **qwerty_map = malloc(26 * sizeof(char *));
    for (int i = 0; i < 26; ++i) {
        qwerty_map[i] = malloc(7);
    }
    strcpy(qwerty_map[0], "qwsz");     // a
    strcpy(qwerty_map[1], "vghn");     // b
    strcpy(qwerty_map[2], "xdfv");     // c
    strcpy(qwerty_map[3], "serfcx");   // d
    strcpy(qwerty_map[4], "wsdr");     // e
    strcpy(qwerty_map[5], "rtgvcd");   // f
    strcpy(qwerty_map[6], "tyhbvf");   // g
    strcpy(qwerty_map[7], "yujnbg");   // h
    strcpy(qwerty_map[8], "ujko");     // i
    strcpy(qwerty_map[9], "uikmnh");   // j
    strcpy(qwerty_map[10], "mjiol");   // k
    strcpy(qwerty_map[11], "pok");     // l
    strcpy(qwerty_map[12], "njk");     // m
    strcpy(qwerty_map[13], "bhjm");    // n
    strcpy(qwerty_map[14], "iklp");    // o
    strcpy(qwerty_map[15], "ol");      // p
    strcpy(qwerty_map[16], "aw");      // q
    strcpy(qwerty_map[17], "edft");    // r
    strcpy(qwerty_map[18], "awedxz");  // s
    strcpy(qwerty_map[19], "rfgy");    // t
    strcpy(qwerty_map[20], "yhji");    // u
    strcpy(qwerty_map[21], "cfgb");    // v
    strcpy(qwerty_map[22], "qase");    // w
    strcpy(qwerty_map[23], "zsdc");    // x
    strcpy(qwerty_map[24], "tghu");    // y
    strcpy(qwerty_map[25], "asx");     // z
    return qwerty_map;
}

void free_qwerty_adjacency_map(char **const map) {
    if (map) {
        for (int i = 0; i < 26; ++i) {
            if (map[i]) {
                free(map[i]);
            }
        }
        free(map);
    }
}

char check_for_adjacency(char **const button_map, const char first_char, const char second_char) {
    char are_adjacent = 0;
    const char *adjacent_to_first = *(button_map + first_char - 'a');
    while (adjacent_to_first[0] && !are_adjacent) {
        are_adjacent = adjacent_to_first[0] == second_char;
        ++adjacent_to_first;
    }
    return are_adjacent;
}
