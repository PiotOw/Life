#ifndef LIFE_GRID_H
#define LIFE_GRID_H
enum cell_state {
    DEAD, ALIVE
};

typedef struct grids {
    int *dim;
    int *grid;
    int *new_grid;
} grids;

void Grid_ChangeGrids(struct grids *grid_gens);
int* Grid_CopyGrid(struct grids *grid_gens);
#endif //LIFE_GRID_H
