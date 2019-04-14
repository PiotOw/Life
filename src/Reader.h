#ifndef LIFE_READER_H
#define LIFE_READER_H
#include "Grid.h"

void Reader_MakeTempFile();

int *Reader_CheckSize(char *input);

cell_state_t* Reader_MakeGrid(char *input, int *dim);


#endif //LIFE_READER_H
