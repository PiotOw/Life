#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void Reader_MakeTempFile() {
    FILE *to = fopen("Reader_TmpFile.txt", "w");
    FILE *from = stdin;

    int file_char;
    while ((file_char = fgetc(from)) != EOF)
        fputc(file_char, to);

    fclose(to);
    fclose(from);
}

int *Reader_CheckSize(char **flags) {
    FILE *in;
    if (strcmp(flags[2], "stdin") == 0) {
        in = fopen("Reader_TmpFile.txt", "r");
    } else {
        in = fopen(flags[2], "r");
    }

    if (in == NULL) {
        fprintf(stderr,
                "Reader_CheckSize: Nie znaleziono pliku z danymi wejściowymi. Przerywam działanie. \n",
                flags[2]);
        exit(1);
    }

    char file_char;                                         //zmienna pomocnicza - poruszanie sie po znakach
    int *dim = malloc(2 * sizeof(int));
    dim[0] = 0;
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
        if (file_char == ')');                                                   //kontrola bledow (w przyszlosci)
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

int *Reader_MakeGrid(char **flags, int *dim) {
    FILE *in;
    if (strcmp(flags[2], "stdin") == 0) {
        in = fopen("Reader_TmpFile.txt", "r");
    } else
        in = fopen(flags[2], "r");

    int width = 0;
    int height = 1;
    int *grid = malloc(dim[0] * dim[1] * sizeof(int));

    int file_char;
    file_char = fgetc(in);
    if (file_char == '(') {
        while ((file_char = fgetc(in)) != '\n');
        file_char = fgetc(in);
    }
    while (file_char != EOF) {
        if (file_char == '0') {
            grid[width + dim[0] * (height - 1)] = 0;
            width++;
        } else if (file_char == '1') {
            grid[width + dim[0] * (height - 1)] = 1;
            width++;
        } else if (isalnum((file_char))) {
            fprintf(stderr,
                    "Reader_MakeGrid: Linia %d znak %d wczytano: \"%c\". Stan automatycznie zmieniony na \"1\" \n",
                    height, width, file_char);
            grid[width + dim[0] * (height - 1)] = 1;
            width++;
        } else if (file_char == '\n') {
            if (width < dim[0]) {
                fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d,"
                                "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                        height, dim[0], width);
                while (width < dim[0]) {
                    grid[width + dim[0] * (height - 1)] = 0;
                    width++;
                }
            }
            width = 0;
            height++;
        }
        if (width > dim[0]) {
            fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Wiersz został skrócony do %d \n",
                    height, dim[0]);
            if (height == dim[1])
                return grid;
            width = 0;
            height++;
            while ((file_char = fgetc(in)) != '\n');
        }
        file_char = fgetc(in);
    }
    if (width < dim[0]) {
        fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d,"
                        "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                height, dim[0], width);
        while (width < dim[0]) {
            grid[width + dim[0] * (height - 1)] = 0;
            width++;
        }
    }

    fclose(in);
    if (strcmp(flags[2], "stdin") == 0)
        remove("Reader_TmpFile.txt");

    return grid;
}
