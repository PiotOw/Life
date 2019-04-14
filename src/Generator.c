#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Generator.h"
#include "Grid.h"
#include "Rules.h"

void Generator_MakeMiniGrid(int *mini_grid, struct grids *grid_gens, int xIndex, int yIndex) {
    for (int i = 0; i < 9; i++) {
        mini_grid[i] = ALIVE;
    }
    int n;
    if (cellIndex % grid_gens->dim[0] == 0) {
        mini_grid[0] = DEAD;
        mini_grid[3] = DEAD;
        mini_grid[6] = DEAD;
    }
    if (cellIndex % grid_gens->dim[0] == grid_gens->dim[0] - 1) {
        mini_grid[2] = DEAD;
        mini_grid[5] = DEAD;
        mini_grid[8] = DEAD;
    }
    if (cellIndex < grid_gens->dim[0]) {
        mini_grid[0] = DEAD;
        mini_grid[1] = DEAD;
        mini_grid[2] = DEAD;
    }
    if (cellIndex > (grid_gens->dim[0] * (grid_gens->dim[1] - 1) - 1)) {
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
                mini_grid[n] = grid_gens->grid[getCellIndex(xIndex + x, yIndex + y, grid_gens->dim[0])];
                n++;
            }
        }
    }
}

void Generator_CreateGen(struct grids *grid_gens) {
    int mini_grid[9];
    for (int y = 0; y < grid_gens->dim[1]; y++) {
        for (int x = 0; x < grid_gens->dim[0]; x++) {
            Generator_MakeMiniGrid(mini_grid, grid_gens, x, y);
            grid_gens->new_grid[getCellIndex(x, y, grid_gens->dim[0])] = Rules_Interpreter(mini_grid);
        }
    }
}

//int main() {
//    int mini_grid[9];
//    grids *grid_gens = malloc(sizeof *grid_gens);
//    int dim[] = {3, 3};
//    int gridt[] = {0,1,0,0,1,0,0,1,0};
//    int gridm[] = {0,0,0,0,0,0,0,0,0};
//    grid_gens->grid = gridt;
//    grid_gens->new_grid = gridm;
//    grid_gens->dim = dim;
//    Generator_CreateGen(grid_gens);
//    printf("\n -----grid------ \n");
//    for (int a = 0; a < grid_gens->dim[1]; a++) {
//        for (int b = 0; b < grid_gens->dim[0]; b++) {
//            printf("%d ", grid_gens->grid[b + a * grid_gens->dim[0]]);
//        }
//        printf("\n");
//    }
//    printf("\n -----new grid------ \n");
//    for (int a = 0; a < grid_gens->dim[1]; a++) {
//        for (int b = 0; b < grid_gens->dim[0]; b++) {
//            printf("%d ", grid_gens->new_grid[b + a * grid_gens->dim[0]]);
//        }
//        printf("\n");
//    }
//}
//    printf("\n");
//    printf("\nindex: %d", index);
//    printf("\n -----mini grid------ \n");
//    for (int a = 0; a < 3; a++) {
//        for (int b = 0; b < 3; b++) {
//            printf("%d ", mini_grid[b + a * 3]);
//        }
//        printf("\n");
//    }
//}

