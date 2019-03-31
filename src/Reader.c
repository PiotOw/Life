#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int* Reader_CheckSize(char** flags) {
    FILE *in;
    if (strcmp(flags[2], "stdin") == 0) {
        in = stdin;
    } else {
        in = fopen(flags[2], "r");
    }

    if (in == NULL) {
        fprintf(stderr, "Reader_CheckSize: Nie można otworzyć pliku \"%s\"\nDane zostaną pobrane ze standardowego wejscia: \n", flags[2]);
        in = stdin;
    }

    char file_char;                                         //zmienna pomocnicza - poruszanie sie po znakach
    int* dim = malloc( 2 * sizeof(int));
    dim[0] = 0;
    dim[1] = 1;
    int maxwidth = 1;

    file_char = fgetc(in);
    if (isspace(file_char)){
        while (isspace(file_char = fgetc(in)))
            ;
    }
    if (file_char  == '(') {                          //czytanie jawnie podanych wartosci
        fscanf(in, "%d", &dim[0]);
        while(isspace(file_char = fgetc(in)));
        if (file_char  == ',')
            fscanf(in, "%d", &dim[1]);
        while(isspace(file_char = fgetc(in)));
        if (file_char  == ')')
            ;                                                   //kontrola bledow (w przyszlosci)
    } else if (isalnum(file_char)) {                        //wyliczanie na podstawie podanej siatki
        while((file_char = fgetc(in)) != EOF) {
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

int* Reader_MakeGrid(char** flags, int* dim){
    FILE *in;
    if (strcmp(flags[2], "stdin") == 0) {
        rewind(stdin);
        in = stdin;
    } else
        in = fopen(flags[2], "r");

    int width = 0;
    int height = 1;
    int* grid = malloc(dim[0] * dim[1] * sizeof(int));

    int file_char;
    file_char = fgetc(in);
    if (file_char == '(') {
        while ( (file_char = fgetc(in)) != '\n')
            ;
        file_char = fgetc(in);
    }
    while(file_char != EOF) {
        if(file_char == '0') {
            grid[width + dim[0] * (height - 1)] = 0;
            width++;
        } else if (file_char == '1') {
            grid[width + dim[0] * (height - 1)] = 1;
            width++;
        } else if (isalnum((file_char))) {
            fprintf(stderr, "Reader_MakeGrid: Linia %d znak %d wczytano: \"%c\". Stan automatycznie zmieniony na \"1\" \n", height, width, file_char);
            grid[width + dim[0] * (height - 1)] = 1;
            width++;
        } else if (file_char == '\n') {
            if (width < dim[0]) {
                fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d,\n"
                                "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                                 height, dim[0], width);
                while (width < dim[0]) {
                    grid[width + dim[0] * (height - 1)] = 0;
                    width++;
                    printf("Y");
                }
            }
            width = 0;
            height++;
        }
        if (width > dim[0]){
            fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Wiersz został skrócony do %d \n", height, dim[0]);
            if(height == dim[1])
                return grid;
            width = 0;
            height++;
            while ( (file_char = fgetc(in)) != '\n')
                printf("X");
        }
        file_char = fgetc(in);
    }
    if (width < dim[0]) {
        fprintf(stderr, "Reader_MakeGrid: Linia %d ma nieprawidłową długość. Powinna mieć %d,\n"
                        "a ma %d. Wiersz został dopełniony martwymi komórkami.\n",
                         height, dim[0], width);
        while (width < dim[0]) {
            grid[width + dim[0] * (height - 1)] = 0;
            width++;
        }
    }

    return grid;
}
