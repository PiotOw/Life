#ifndef LIFE_READER_H
#define LIFE_READER_H

void Reader_MakeTempFile();

int *Reader_CheckSize(char *input);

int *Reader_MakeGrid(char *input, int *dim);


#endif //LIFE_READER_H
