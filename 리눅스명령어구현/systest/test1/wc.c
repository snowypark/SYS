#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    STATE_OUTSIDE_WORD,
    STATE_INSIDE_WORD
} WordState;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [file1] [file2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Failed to open file");
            continue;
        }

        int lines = 0;
        int words = 0;
        int characters = 0;

        int c;
        WordState state = STATE_OUTSIDE_WORD;

        while ((c = fgetc(file)) != EOF) {
            characters++;

            if (c == '\n') {
                lines++;
            }

            if (isspace(c)) {
                state = STATE_OUTSIDE_WORD;
            } else if (state == STATE_OUTSIDE_WORD) {
                state = STATE_INSIDE_WORD;
                words++;
            }
        }

        fclose(file);

        printf("File: %s\n", filename);
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", characters);
        printf("\n");
    }

    return 0;
}

