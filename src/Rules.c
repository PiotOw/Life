#include <stdio.h>
#include "Grid.h"
#include "Rules.h"

cell_state_t Rules_Interpreter(cell_state_t *mini_grid) {
    int aliveCount = 0;
    int cellState = mini_grid[4];
    for (int i = 0; i < 9; i++) {
        aliveCount += mini_grid[i];
    }
    if (cellState) {
        if (aliveCount == 3 || aliveCount == 4) {
            return ALIVE;
        } else {
            return DEAD;
        }

    } else {
        if (aliveCount == 3) {
            return ALIVE;
        } else {
            return DEAD;
        }
    }
}