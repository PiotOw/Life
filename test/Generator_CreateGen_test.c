#include "../src/Grid.h"
#include "../src/Generator.h"
#include "../src/Rules.h"
#include <stdlib.h>
#include <stdio.h>

int Generator_CreateGen_test1() {
    int success = 1;
    cell_state_t mini_grid[9];
    grids *grid_gens = malloc(sizeof *grid_gens);
    int dim[] = {3, 3};
    cell_state_t gridt[] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
    cell_state_t gridm[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    cell_state_t gridFinal[] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
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
    cell_state_t mini_grid[16];
    grids *grid_gens = malloc(sizeof *grid_gens);
    int dim[] = {4, 4};
    cell_state_t gridt[] = {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0};
    cell_state_t gridm[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cell_state_t gridFinal[] = {1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0};
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

int main(){
    int successful = 0;
    if(Generator_CreateGen_test1()){
        printf("Test nr 1 funkcji Generator_CreateGen() nie powiódł się\n");
    }
    else{
        successful++;
    }
    if(Generator_CreateGen_test1()){
        printf("Test nr 2 funkcji Generator_CreateGen() nie powiódł się\n");
    }
    else{
        successful++;
    }
    printf("%d / 2 testy funkcji Generator_CreateGen() zakończyły się powodzeniem\n", successful);
}