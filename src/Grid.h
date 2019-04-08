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
cell_state_t* Grid_CopyGrid(struct grids *grid_gens);
#endif //LIFE_GRID_H
