#include "../src/Rules.h"
#include <stdio.h>
#include "../src/Grid.h"

int Rules_Interpreter_Test1() {
    int grid[9] = {DEAD, DEAD, DEAD, DEAD, ALIVE, DEAD, DEAD, ALIVE, DEAD};
    int x = Rules_Interpreter(grid);
    if (x == DEAD) {
        return 0;
    } else return 1;
}

int Rules_Interpreter_Test2() {
    int grid[9] = {DEAD, DEAD, ALIVE, DEAD, ALIVE, DEAD, DEAD, ALIVE, ALIVE};
    x = Rules_Interpreter(grid);
    if (x == ALIVE) {
        return 0;
    } else return 1;
}