#include "Grid.h"
#include "Reader.h"
#include <stdlib.h>
#include <stdio.h>

void Grid_ChangeGrids(struct grids *grid_gens) {
    for (int i = 0; i < grid_gens->dim[0] * grid_gens->dim[1]; i++)
        grid_gens->grid[i] = grid_gens->new_grid[i];
}

int getCellIndex(int x, int y, int width){
    int index = x + width * y;
    return index;
}

int *Grid_CopyGrid(int *grid, int *dim) {
    int *rgrid = malloc(dim[0] * dim[1] * sizeof(int));
    for (int i = 0; i < dim[0] * dim[1]; i++)
        rgrid[i] = grid[i];
    return rgrid;
}

grids *Grid_CreateGridGens(char *input) {
    int *rdim = Reader_CheckSize(input);
    int *rgrid = Reader_MakeGrid(input, rdim);

    grids *grid_gens = malloc(sizeof *grid_gens);
    grid_gens->dim = rdim;
    grid_gens->grid = rgrid;
    grid_gens->new_grid = Grid_CopyGrid(grid_gens->grid, grid_gens->dim);
    return grid_gens;
}