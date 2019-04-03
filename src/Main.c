#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Reader.h"
#include "Generator.h"
#include "Grid.h"
#include "Formatted_writer.h"
#include "AsciiArt_writer.h"

char** Flags_Interpreter(char **argv, int argc) {
    char **flags = malloc(6 * sizeof *flags);
    flags[0] = "5";             //gen
    flags[1] = "y";             //print
    flags[2] = "stdin";         //input
    flags[3] = "stdout";        //output
    flags[4] = "0";             //dead
    flags[5] = "1";             //alive
    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "--gen") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-' && i < argc - 1) {
                flags[0] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--gen\' została podana bez wartości, domyślna wartość to 5 \n");
            }
        } else if (strcmp(argv[i], "--print") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[1] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--print\' została podana bez wartości, domyślna wartość to y \n");
            }
        } else if (strcmp(argv[i], "--input") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[2] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--input\' została podana bez wartości, dane zostaną pobrane ze standardowego wejścia \n");
            }
        } else if (strcmp(argv[i], "--output") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[3] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--output\' została podana bez wartości, wyniki zostaną wypisane na standardowe wyjście \n");
            }
        } else if (strcmp(argv[i], "--dead") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[4] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--dead\' została podana bez wartości, domyślna wartość to \'0\' \n");
            }
        } else if (strcmp(argv[i], "--alive") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[5] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--alive\' została podana bez wartości, wyniki zostaną pobrane ze standardowego wejścia \n");
            }
        }
    }
    return flags;
}

void Check_Flags(char **flags) {
    if (atoi(flags[0]) > 1000) {
        printf("Check_Flags: Nieprawidłowa wartość flagi \'--gen\', domyślna wartość to 5 \n");
        flags[0] = "5";
    } else {
        for (int i = 0; i < strlen(flags[0]); i++) {
            if (isdigit(*(flags[0] + i)) == 0) {
                printf("Check_Flags: Nieprawidłowa wartość flagi \'--gen\', domyślna wartość to 5 \n");
                flags[0] = "5";
                break;
            }
        }
    }

    if (strcmp(flags[1], "y") != 0 && strcmp(flags[1], "n") != 0) {
        flags[1] = "y";
        fprintf(stderr, "Check_Flags: Nieprawidłowa wartość flagi \'--print\', domyślna wartość to y \n");
    }


}

int main(int argc, char **argv) {
    char** flags = Flags_Interpreter(argv, argc);
    Check_Flags(flags);
    if (strcmp(flags[2], "stdin") == 0)
        Reader_MakeTempFile();
    int *rdim = Reader_CheckSize(flags);
    int *rgrid = Reader_MakeGrid(flags, rdim);

    grids *grid_gens = malloc(sizeof *grid_gens);
    grid_gens->dim = rdim;
    grid_gens->grid = rgrid;
    grid_gens->new_grid = Grid_CopyGrid(grid_gens);
    int tmp_print = -1;                      //zmienna potrzebna do wypisania generacji wprowadzanej
    AsciiArt_Print(tmp_print, flags, grid_gens);

    for (int i = 0; i < atoi(flags[0]); i++) {
        Generator_CreateGen(grid_gens);
        AsciiArt_Print(i, flags, grid_gens);
        Grid_ChangeGrids(grid_gens);
    }

    Formatted_Print(flags, grid_gens);

    return 0;


}

