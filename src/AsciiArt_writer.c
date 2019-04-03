#include <stdlib.h>
#include <stdio.h>
#include "AsciiArt_writer.h"
#include "Grid.h"

void AsciiArt_Print(int nfile, char **flags, struct grids *grid_gens) {
    FILE *out;
    char filename[] = "Generations/gen0000.txt\0";
    if (nfile == -1) {
        filename[18] = (nfile + 1) + '0';
    } else if (nfile + 1 < 10) {
        filename[18] = (nfile + 1) + '0';
    } else if (nfile + 1 < 100) {
        filename[17] = (nfile + 1) / 10 + '0';
        filename[18] = (nfile + 1) % 10 + '0';
    } else if (nfile + 1 < 1000) {
        filename[16] = (nfile + 1) / 100 + '0';
        filename[17] = ((nfile + 1) / 10) % 10 + '0';
        filename[18] = (nfile + 1) % 10 + '0';
    } else if (nfile + 1 == 1000) {
        filename[15] = '1';
        filename[16] = '0';
        filename[17] = '0';
        filename[18] = '0';
    }


    out = fopen(filename, "w");
    for (int i = 0; i < grid_gens->dim[0] + 2; i++)
        fprintf(out, "-");
    fprintf(out, "\n");
    for (int height = 0; height < grid_gens->dim[1]; height++) {
        fprintf(out, "|");
        for (int width = 0; width < grid_gens->dim[0]; width++) {
            fprintf(out, "%s", (grid_gens->new_grid[width + (grid_gens->dim[0] * height)] == 0 ? flags[4] : flags[5]));
        }
        fprintf(out, "|\n");
    }
    for (int i = 0; i < grid_gens->dim[0] + 2; i++)
        fprintf(out, "-");
    fprintf(out, "\n");

    fclose(out);
}
/*
int main() {
    grids *grid_gens = malloc(sizeof *grid_gens);
    char **flags = malloc(6 * sizeof *flags);
    flags[0] = "5";             //gen
    flags[1] = "y";             //print
    flags[2] = "stdin";         //input
    flags[3] = "stdout";        //output
    flags[4] = "0";             //dead
    flags[5] = "1";             //alive

    int ndim[] = {9, 5};
    grid_gens->dim = ndim;
    int grid[] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
                  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int grid2[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
                   0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    grid_gens->new_grid = grid;
    grid_gens->grid = grid2;
    for(int i = 0 ; i < 1000 ; i++)
    AsciiArt_Print(i, flags, grid_gens);


    return 0;
}
*/