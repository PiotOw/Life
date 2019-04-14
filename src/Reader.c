#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Reader.h"
#include "Grid.h"

void Reader_MakeTempFile() {
    FILE *to = fopen("Reader_TmpFile.txt", "w");
    FILE *from = stdin;

    int file_char;
    while ((file_char = fgetc(from)) != EOF)
        fputc(file_char, to);

    fclose(to);
    fclose(from);
}

int *Reader_CheckSize(char *input) {
    FILE *in;
    if (strcmp(input, "stdin") == 0) {
        in = fopen("Reader_TmpFile.txt", "r");
    } else {
        in = fopen(input, "r");
    }

    if (in == NULL) {
        fprintf(stderr,
                "Reader_CheckSize: Nie znaleziono pliku z danymi wejściowymi. Przerywam działanie. \n");
        exit(1);
    }

    char file_char;                                         //zmienna pomocnicza - poruszanie sie po znakach
    int *dim = malloc(2 * sizeof(int));
    dim[0] = 1;
    dim[1] = 1;
    int maxwidth = 1;

    file_char = fgetc(in);
    if (isspace(file_char)) {
        while (isspace(file_char = fgetc(in)));
    }
    if (file_char == '(') {                          //czytanie jawnie podanych wartosci
        fscanf(in, "%d", &dim[0]);
        while (isspace(file_char = fgetc(in)));
        if (file_char == ',')
            fscanf(in, "%d", &dim[1]);
        while (isspace(file_char = fgetc(in)));
        if (file_char != ')')
            fprintf(stderr,
                    "Ale wtopa, podane wymiary nie mają \')\'\n");                                                   //kontrola bledow (w przyszlosci)
    } else if (isalnum(file_char)) {                        //wyliczanie na podstawie podanej siatki
        while ((file_char = fgetc(in)) != EOF) {
            if (isalnum(file_char))
                maxwidth++;
            else if (file_char == '\n') {
                if (dim[0] < maxwidth)
                    dim[0] = maxwidth;
                maxwidth = 0;
                dim[1]++;
            }
        }
        if (dim[0] < maxwidth)
            dim[0] = maxwidth;

    }
    fclose(in);
    return dim;
}

int *Reader_MakeGrid(char *input, int *dim) {
    FILE *in;
    if (strcmp(input, "stdin") == 0) {
        in = fopen("Reader_TmpFile.txt", "r");
    } else
        in = fopen(input, "r");

    int width = 0;
    int height = 0;
    int *grid = malloc(dim[0] * dim[1] * sizeof(int));

    int file_char;
    file_char = fgetc(in);
    if (file_char == '(') {
        while ((file_char = fgetc(in)) != '\n');
        file_char = fgetc(in);
    }
    while (file_char != EOF) {
        if (file_char == '0') {
            grid[getCellIndex(width, height, dim[0])] = DEAD;
            width++;
        } else if (file_char == '1') {
            grid[getCellIndex(width, height, dim[0])] = ALIVE;
            width++;
        } else if (isalnum((file_char))) {
            fprintf(stderr,
                    "Reader_MakeGrid: Linia %d znak %d wczytano: \"%c\". Stan automatycznie zmieniony na \"1\" \n",
                    height + 1, width, file_char);
            grid[getCellIndex(width, height, dim[0])] = ALIVE;
            width++;


        } else if (file_char == '\n') {
            if (width < dim[0]) {
                fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d, "
                                "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                        height + 1, dim[0], width);
                while (width < dim[0]) {
                    grid[getCellIndex(width, height, dim[0])] = DEAD;
                    width++;
                }
            }
            width = 0;
            if (height + 1 < dim[1])
                height++;
            else {
                fprintf(stderr, "Reader_MakeGrid: Wprowadzono zbyt wiele Linii. Przeczytano do linii %d \n",
                        height + 1);
                return grid;
            }
        }
        if (width > dim[0]) {
            fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Wiersz został skrócony do %d \n",
                    height + 1, dim[0]);
            while ((file_char = fgetc(in)) != '\n' && file_char != EOF);
            width = 0;
            if (height + 1 < dim[1])
                height++;
            else {
                fprintf(stderr, "Reader_MakeGrid: Wprowadzono zbyt wiele Linii. Przeczytano do linii nr %d \n",
                        height + 1);
                return grid;
            }
        }
        file_char = fgetc(in);
    }
    if (width < dim[0] && height < dim[1]) {
        fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d, "
                        "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                height + 1, dim[0], width);
        while (width < dim[0]) {
            grid[getCellIndex(width, height, dim[0])] = DEAD;
            width++;
        }
        height++;
        width = 0;
    }
    if (height != dim[1]) {
        fprintf(stderr, "Reader_MakeGrid: Wprowadzono za mało linii. Pozostałe linie uzupełniono zerami\n");
        for (; height < dim[1]; height++) {
            while (width < dim[0]) {
                grid[getCellIndex(width, height, dim[0])] = DEAD;
                width++;
            }
            width = 0;
        }

    }

    fclose(in);
    if (strcmp(input, "stdin") == 0)
        remove("Reader_TmpFile.txt");

    return grid;
}
