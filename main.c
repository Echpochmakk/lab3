#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "X.c"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [--generate N | --sort | --print]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "--generate") == 0 || strcmp(argv[1], "-g") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s --generate N [--out output.csv]\n", argv[0]);
            return EXIT_FAILURE;
        }
        int n = atoi(argv[2]);
        const char *output_file = NULL;

        for (int i = 3; i < argc; i++) {
            if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            }
        }
        generate_data(n, output_file);

    } else if (strcmp(argv[1], "--sort") == 0 || strcmp(argv[1], "-s") == 0) {
        const char *input_file = NULL;
        const char *output_file = NULL;
        int ascending = 1;

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 || strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            } else if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            } else if (strcmp(argv[i], "--type") == 0 || strcmp(argv[i], "-t") == 0) {
                if (strcmp(argv[++i], "desc") == 0 || strcmp(argv[i], "D") == 0) {
                    ascending = 0;
                }
            }
        }

        sort_data(input_file, output_file, ascending);
    } else if (strcmp(argv[1], "--print") == 0 || strcmp(argv[1], "-P") == 0) {
        const char *input_file = NULL;
        const char *output_file = NULL;
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 || strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            } else if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            }
        }
        print_data(input_file, output_file);

    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
