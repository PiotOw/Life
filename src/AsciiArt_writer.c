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
            fprintf(out, "%c", (grid_gens->new_grid[Grid_GetCellIndex(column, row, w)] == 0 ? dead : alive));
        }
        fprintf(out, "|\n");
    }
    for (int i = 0; i < w + 2; i++)
        fprintf(out, "-");
    fprintf(out, "\n");

    fclose(out);
}