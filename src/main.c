#include <stdio.h>
#include <stdlib.h>

#include "adjacency.h"

void lowercase_string(char *str);

int main(int argc, char **argv) {
    char work_error = 0;

    char *filename = NULL;
    if (argc != 2) {
        work_error = 1;
    } else {
        filename = argv[1];
    }

    FILE *input_data = NULL;
    if (!work_error && !(input_data = fopen(filename, "r"))) {
        work_error = 1;
    }

    if (!work_error) {
        char **qwerty_map = NULL;
        int good_words_count = 0;
        qwerty_map = get_qwerty_adjacency_map();
        char *current_word = NULL;
        long unsigned int current_word_buff_size = 0;
        long int word_size = 0;
        while ((word_size = getline(&current_word, &current_word_buff_size, input_data)) > 0) {
            // omit the newline
            if (current_word[word_size - 1] == '\n') {
                current_word[word_size - 1] = '\0';
            }
            lowercase_string(current_word);
            char current_word_is_good = 1;
            for (int i = 1; current_word_is_good && current_word[i - 1] && current_word[i]; ++i) {
                if (!check_for_adjacency(qwerty_map, current_word[i], current_word[i - 1])) {
                    current_word_is_good = 0;
                }
            }
            if (current_word_is_good) {
                ++good_words_count;
            }
        }
        if (current_word) {
            free(current_word);
        }
        if (qwerty_map) {
            free_qwerty_adjacency_map(qwerty_map);
        }
        printf("%d\n", good_words_count);
    } else {
        printf("n/a\n");
    }

    if (input_data) {
        fclose(input_data);
    }
    return work_error;
}

void lowercase_string(char *str) {
    while (str[0]) {
        if (str[0] >= 'A' && str[0] <= 'Z') {
            str[0] = str[0] - 'A' + 'a';
        }
        ++str;
    }
}
