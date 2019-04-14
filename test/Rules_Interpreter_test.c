#include "../src/Rules.h"
#include <stdio.h>
#include "../src/Grid.h"

int Rules_Interpreter_Test1() {
    cell_state_t grid[9] = {DEAD, DEAD, DEAD, DEAD, ALIVE, DEAD, DEAD, ALIVE, DEAD};
    cell_state_t x = Rules_Interpreter(grid);
    if (x == DEAD) {
        return 0;
    } else return 1;
}

int Rules_Interpreter_Test2() {
    cell_state_t grid[9] = {DEAD, DEAD, ALIVE, DEAD, ALIVE, DEAD, DEAD, ALIVE, ALIVE};
    cell_state_t x = Rules_Interpreter(grid);
    if (x == ALIVE) {
        return 0;
    } else return 1;
}

int main(){
    int successful = 0;
    if(Rules_Interpreter_Test1()){
        printf("Test nr 1 funkcji Rules_Interpreter() nie powiódł się\n");
    }
    else{
        successful++;
    }
    if(Rules_Interpreter_Test2()){
        printf("Test nr 2 funkcji Rules_Interpreter() nie powiódł się\n");
    }
    else{
        successful++;
    }
    printf("%d / 2 testy funkcji Rules_Interpreter() zakończyły się powodzeniem\n", successful);

}