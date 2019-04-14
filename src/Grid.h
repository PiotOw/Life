#ifndef LIFE_GRID_H
#define LIFE_GRID_H
typedef enum cell_state {
    DEAD, ALIVE
} cell_state_t;

typedef struct grids {
    int *dim;
    cell_state_t *grid;
    cell_state_t *new_grid;
} grids;

void Grid_ChangeGrids(struct grids *grid_gens);

int Grid_GetCellIndex(int x, int y, int width);

cell_state_t* Grid_CopyGrid(cell_state_t *grid, int *dim);     // zwraca cell_state_t*
grids *Grid_CreateGridGens(char *input);
#endif //LIFE_GRID_H
