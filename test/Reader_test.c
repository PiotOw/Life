#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../src/Reader.h"
#include "../src/Grid.h"


int ReaderTest1() {
    char *input = "Reader_test1.txt";
    int *dim = Reader_CheckSize(input);
    cell_state_t *grid = Reader_MakeGrid(input, dim);
    int g_test[] = {1, 0, 1, 0, 0,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 0, 0,
                    0, 0, 0, 0, 0};

    for (int i = 0; i < dim[0] * dim[1]; i++) {
        if (grid[i] != g_test[i])
            return 1;
    }

    free(dim);
    free(grid);

    return 0;
}

int ReaderTest2() {
    char *input = "Reader_test2.txt";
    int *dim = Reader_CheckSize(input);
    cell_state_t *grid = Reader_MakeGrid(input, dim);
    int g_test[] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                    1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
                    1, 1, 1, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
                    0, 0, 0, 1, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < dim[0] * dim[1]; i++) {
        if (grid[i] != g_test[i])
            return 1;
    }

    free(dim);
    free(grid);

    return 0;
}

int main() {
    int i = 0;
    if (ReaderTest1() == 0)
        i++;
    else
        printf("Test nr 1 nie powiódł się\n");

    if (ReaderTest2() == 0)
        i++;
    else
        printf("Test nr 2 nie powiódł się\n");

    printf("****Powiodło się %d/2****\n", i);
    return 0;
}
