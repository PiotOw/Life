#ifndef LIFE_GRID_H
#define LIFE_GRID_H
typedef enum cell_state {
    DEAD, ALIVE
} cell_state_t;

typedef struct grids {
    int *dim;
    int *grid;
    int *new_grid;
} grids;

void Grid_ChangeGrids(struct grids *grid_gens);

int getCellIndex(int x, int y);

int *Grid_CopyGrid(int *grid, int *dim);     // zwraca cell_state_t*
grids *Grid_CreateGridGens(char *input);
#endif //LIFE_GRID_H
