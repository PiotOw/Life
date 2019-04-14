#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Reader.h"
#include "Generator.h"
#include "Grid.h"
#include "Formatted_writer.h"
#include "AsciiArt_writer.h"

typedef struct flags_t {
    int gen;
    char print;
    char *input;
    char *output;
    char dead;
    char alive;
} flags_t;

flags_t *CreateFlags() {
    flags_t *flags = malloc(sizeof *flags);
    flags->gen = 5;
    flags->print = 'y';
    flags->input = "stdin";
    flags->output = "stdout";
    flags->dead = '0';
    flags->alive = '1';
    return flags;
}

void FlagsInterpreter(char **argv, int argc, struct flags_t *flags) {
    char *err;

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "--gen") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-' && i < argc - 1) {
                flags->gen = strtol(argv[++i], &err, 10);
                if (*err || flags->gen > 1000) {
                    printf("Check_Flags: Nieprawidłowa wartość flagi \'--gen\', domyślna wartość to 5 \n");
                    flags->gen = 5;
                }
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--gen\' została podana bez wartości, domyślna wartość to 5 \n");
            }
        } else if (strcmp(argv[i], "--print") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                if (strcmp(argv[i + 1], "y") == 0)
                    flags->print = 'y';
                else if (strcmp(argv[i + 1], "n") == 0)
                    flags->print = 'n';
                else
                    fprintf(stderr,
                            "FlagsInterpreter: Nieprawidłowa wartość flagi \'--print\', domyślna wartość to y \n");
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--print\' została podana bez wartości, domyślna wartość to y \n");
            }
        } else if (strcmp(argv[i], "--input") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags->input = argv[++i];
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--input\' została podana bez wartości, dane zostaną pobrane ze standardowego wejścia \n");
            }
        } else if (strcmp(argv[i], "--output") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags->output = argv[++i];
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--output\' została podana bez wartości, wyniki zostaną wypisane na standardowe wyjście \n");
            }
        } else if (strcmp(argv[i], "--dead") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags->dead = *argv[++i];
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--dead\' została podana bez wartości, domyślna wartość to \'0\' \n");
            }
        } else if (strcmp(argv[i], "--alive") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags->alive = *argv[++i];
            } else {
                fprintf(stderr,
                        "FlagsInterpreter: Flaga \'--alive\' została podana bez wartości, wyniki zostaną pobrane ze standardowego wejścia \n");
            }
        }
    }
}

void MemoryFree(struct grids *grid_gens, struct flags_t *flags) {
    free(grid_gens->dim);
    free(grid_gens->grid);
    free(grid_gens->new_grid);
    free(grid_gens);

    free(flags);
}


int main(int argc, char **argv) {
    flags_t *flags = CreateFlags();
    FlagsInterpreter(argv, argc, flags);

    if (strcmp(flags->input, "stdin") == 0)
        Reader_MakeTempFile();

    grids *grid_gens = Grid_CreateGridGens(flags->input);

    if (flags->print == 'y') {
        int tmp_print = -1;                      //zmienna potrzebna do wypisania wprowadzanej generacji
        AsciiArt_Print(tmp_print, grid_gens, flags->dead, flags->alive);
    }

    for (int i = 0; i < flags->gen; i++) {
        Generator_CreateGen(grid_gens);
        if (flags->print == 'y') AsciiArt_Print(i, grid_gens, flags->dead, flags->alive);
        Grid_ChangeGrids(grid_gens);
    }

    Formatted_Print(flags->output, grid_gens);

    MemoryFree(grid_gens, flags);

    return 0;


}

