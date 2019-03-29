#ifndef LIFE_GRID_H
#define LIFE_GRID_H
enum cell_state {
    DEAD, ALIVE
};

typedef struct grids {
    int grid[];
    int new_grid[];
    int dim[2];
} grids;
#endif //LIFE_GRID_H
