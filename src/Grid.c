#include "Grid.h"
#include <stdlib.h>

void Grid_ChangeGrids(struct grids *grid_gens) {
    for (int i = 0; i < grid_gens->dim[0] * grid_gens->dim[1]; i++)
        grid_gens->grid[i] = grid_gens->new_grid[i];
}

int* Grid_CopyGrid(struct grids *grid_gens) {
    int *rgrid = malloc(grid_gens->dim[0] * grid_gens->dim[1] * sizeof(int));
    for (int i = 0; i < grid_gens->dim[0] * grid_gens->dim[1]; i++)
        rgrid[i] = grid_gens->grid[i];
    return  rgrid;
}