#include <stdio.h>

int Rules_Interpreter(int *mini_grid) {
    int aliveCaunt = 0;
    int cellState = mini_grid[4];
    for (int i = 0; i < 9; i++) {
        aliveCaunt += mini_grid[i];
    }
    if (cellState) {
        if (aliveCaunt == 3 || aliveCaunt == 4) {
            return 1;
        } else {
            return 0;
        }

    } else {
        if (aliveCaunt == 3) {
            return 1;
        } else {
            return 0;
        }
    }
}
/*

int main() {
    int grid[9] = {0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,0};
    int x = Rules_Interpreter(grid);
    printf("%d \n", x);
}
*/
