#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Generator.h"
#include "Grid.h"
#include "Rules.h"

void Generator_MakeMiniGrid(cell_state_t *mini_grid, struct grids *grid_gens, int xIndex, int yIndex) {
    for (int i = 0; i < 9; i++) {
        mini_grid[i] = ALIVE;
    }
    int n;
    if (xIndex == 0) {
        mini_grid[0] = DEAD;
        mini_grid[3] = DEAD;
        mini_grid[6] = DEAD;
    }
    if (xIndex == grid_gens->dim[0] - 1) {
        mini_grid[2] = DEAD;
        mini_grid[5] = DEAD;
        mini_grid[8] = DEAD;
    }
    if (yIndex == 0) {
        mini_grid[0] = DEAD;
        mini_grid[1] = DEAD;
        mini_grid[2] = DEAD;
    }
    if (yIndex == grid_gens->dim[1] - 1) {
        mini_grid[6] = DEAD;
        mini_grid[7] = DEAD;
        mini_grid[8] = DEAD;
    }
    n = 0;
    for (int y = -1; y <= +1; y++) {
        for (int x = -1; x <= +1; x++) {
            if (mini_grid[n] == DEAD) {
                n++;
            } else {
                mini_grid[n] = grid_gens->grid[Grid_GetCellIndex(xIndex + x, yIndex + y, grid_gens->dim[0])];
                n++;
            }
        }
    }
}

void Generator_CreateGen(struct grids *grid_gens) {
    cell_state_t mini_grid[9];
    for (int y = 0; y < grid_gens->dim[1]; y++) {
        for (int x = 0; x < grid_gens->dim[0]; x++) {
            Generator_MakeMiniGrid(mini_grid, grid_gens, x, y);
            grid_gens->new_grid[Grid_GetCellIndex(x, y, grid_gens->dim[0])] = Rules_Interpreter(mini_grid);
        }
    }
}