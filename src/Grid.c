#include "grid.h"

void Grid_ChangeGrids(struct grids *grid_gens) {
    for (int i = 0; i < grid_gens->dim[0] * grid_gens->dim[1]; i++)
        grid_gens->grid[i] = grid_gens->new_grid[i];
}