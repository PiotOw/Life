#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "..\src\Reader.h"

int main() {
    printf("****TEST 1****\n");
    char **flags = malloc(6 * sizeof *flags);
    flags[2] = "Reader_test1.txt";
    int *dim1 = Reader_CheckSize(flags);
    int *grid1 = Reader_MakeGrid(flags, dim1);

    for (int i = 0; i < dim1[0] * dim1[1]; i++) {
        printf("%d", grid1[i]);
        if ((i + 1) % dim1[0] == 0)
            printf("\n");
    }


    printf("\n\n****TEST 2****\n");
    flags[2] = "Reader_test2.txt";
    int *dim2 = Reader_CheckSize(flags);
    int *grid2 = Reader_MakeGrid(flags, dim2);

    for (int i = 0; i < dim2[0] * dim2[1]; i++) {
        printf("%d", grid2[i]);
        if ((i + 1) % dim2[0] == 0)
            printf("\n");
    }
}
