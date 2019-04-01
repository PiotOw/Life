#include <stdio.h>
#include <string.h>
#include "Formatted_writer.h"
#include "Grid.h"

void Formatted_Print(char **flags, struct grids *grid_gens) {
    FILE *out;
    if (strcmp(flags[3], "stdout") == 0)
        out = stdout;
    else
        out = fopen(flags[3], "w");
    fprintf(out, "(%d , %d)\n", grid_gens->dim[0], grid_gens->dim[1]);
    for (int i = 0; i < grid_gens->dim[0] * grid_gens->dim[1]; i++) {
        fprintf(out, "%d", grid_gens->grid[i]);
        if ((i + 1) % grid_gens->dim[0] == 0 && (i + 1) != grid_gens->dim[0] * grid_gens->dim[1])
            fprintf(out, "\n");
    }

    fclose(out);
}