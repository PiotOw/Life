#include <stdlib.h>
#include <stdio.h>
#include "AsciiArt_writer.h"
#include "Grid.h"

void AsciiArt_Print(int nfile, struct grids *grid_gens, char dead, char alive) {
    FILE *out;
    char filename[25];
    sprintf(filename, "Generations/gen%04d.txt", nfile + 1);
    out = fopen(filename, "w");

    int w = grid_gens->dim[0];
    int h = grid_gens->dim[1];

    for (int i = 0; i < w + 2; i++)
        fprintf(out, "-");
    fprintf(out, "\n");
    for (int row = 0; row < h; row++) {
        fprintf(out, "|");
        for (int column = 0; column < w; column++) {
            fprintf(out, "%c", (grid_gens->new_grid[column + (w * row)] == 0 ? dead : alive));
        }
        fprintf(out, "|\n");
    }
    for (int i = 0; i < w + 2; i++)
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