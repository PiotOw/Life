#include "../src/Grid.h"
#include "../src/Generator.h"
#include "../src/Rules.h"
#include <stdlib.h>
#include <stdio.h>

int Generator_CreateGen_test1() {
    int success = 1;
    int mini_grid[9];
    grids *grid_gens = malloc(sizeof *grid_gens);
    int dim[] = {3, 3};
    int gridt[] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
    int gridm[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int gridFinal[] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
    grid_gens->grid = gridt;
    grid_gens->new_grid = gridm;
    grid_gens->dim = dim;
    Generator_CreateGen(grid_gens);
    for (int i = 0; i < 9; i++) {
        if (grid_gens->new_grid[i] != gridFinal[i]) {
            success = 0;
        }
    }
    if (success) {
        return 0;
    } else {
        return 1;
    }
}

int Generator_CreateGen_test2() {
    int success = 1;
    int mini_grid[16];
    grids *grid_gens = malloc(sizeof *grid_gens);
    int dim[] = {4, 4};
    int gridt[] = {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0};
    int gridm[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int gridFinal[] = {1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0};
    grid_gens->grid = gridt;
    grid_gens->new_grid = gridm;
    grid_gens->dim = dim;
    Generator_CreateGen(grid_gens);
    for (int i = 0; i < 16; i++) {
        if (grid_gens->new_grid[i] != gridFinal[i]) {
            success = 0;
        }
    }
    if (success) {
        return 0;
    } else {
        return 1;
    }
}