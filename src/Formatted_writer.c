#include <stdio.h>
#include <string.h>
#include "Formatted_writer.h"
#include "Grid.h"

void Formatted_Print(char *output, struct grids *grid_gens) {
    FILE *out;
    if (strcmp(output, "stdout") == 0)
        out = stdout;
    else
        out = fopen(output, "w");

    int w = grid_gens->dim[0];
    int h = grid_gens->dim[1];

    fprintf(out, "(%d , %d)\n", w, h);
    for (int i = 0; i < w * h; i++) {
        fprintf(out, "%d", grid_gens->grid[i]);
        if ((i + 1) % w == 0 && (i + 1) != w * h)
            fprintf(out, "\n");
    }
    fclose(out);
}