#include "adjacency.h"

const char **get_qwerty_adjacency_map(void) {
    const char **qwerty_map = malloc(26 * sizeof(char *));
    qwerty_map[0] = "qwsz";     // a
    qwerty_map[1] = "vghn";     // b
    qwerty_map[2] = "xdfv";     // c
    qwerty_map[3] = "serfcx";   // d
    qwerty_map[4] = "wsdr";     // e
    qwerty_map[5] = "rtgvcd";   // f
    qwerty_map[6] = "tyhbvf";   // g
    qwerty_map[7] = "yujnbg";   // h
    qwerty_map[8] = "ujko";     // i
    qwerty_map[9] = "uikmnh";   // j
    qwerty_map[10] = "mjiol";   // k
    qwerty_map[11] = "pok";     // l
    qwerty_map[12] = "njk";     // m
    qwerty_map[13] = "bhjm";    // n
    qwerty_map[14] = "iklp";    // o
    qwerty_map[15] = "ol";      // p
    qwerty_map[16] = "aw";      // q
    qwerty_map[17] = "edft";    // r
    qwerty_map[18] = "awedxz";  // s
    qwerty_map[19] = "rfgy";    // t
    qwerty_map[20] = "yhji";    // u
    qwerty_map[21] = "cfgb";    // v
    qwerty_map[22] = "qase";    // w
    qwerty_map[23] = "zsdc";    // x
    qwerty_map[24] = "tghu";    // y
    qwerty_map[25] = "asx";     // z
    return qwerty_map;
}

char check_for_adjacency(const char **const button_map, const char first_char, const char second_char) {
    char are_adjacent = first_char == second_char;
    const char *adjacent_to_first = "";
    if (first_char >= 'a' && first_char <= 'z' && second_char >= 'a' && second_char <= 'z') {
        adjacent_to_first = *(button_map + first_char - 'a');
    }
    while (adjacent_to_first[0] && !are_adjacent) {
        are_adjacent = adjacent_to_first[0] == second_char;
        ++adjacent_to_first;
    }
    return are_adjacent;
}
