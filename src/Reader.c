#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int* Reader_CheckSize(char** flags) {
    FILE *in;
    if (strcmp(flags[2], "stdin"))
        in = stdin;
    else
        in = fopen(flags[2], "r");

    if (in == NULL) {
        fprintf(stderr, "Reader_CheckSize: Nie można otworzyć pliku %s", flags[2]);
        exit(1);
    }

    char file_char;                                             //
    int* size = malloc( 2 * sizeof(int));
    size[0] = 0;
    size[1] = 1;
    int maxwidth = 1;
    if ((file_char = fgetc(in)) == '(') {                   //czytanie jawnie podanych wartosci
        fscanf(in, "%d", &size[0]);
        while(isspace(file_char = fgetc(in)));                  //pomijanie spacji
        if (file_char  == ',')
            fscanf(in, "%d", &size[1]);
        while(isspace(file_char = fgetc(in)));                  //pomijanie spacji
        if (file_char  == ')')
            printf("()");
    } else if (isalnum(file_char)) {                        //wyliczanie na podstawie podanej siatki
        while((file_char = fgetc(in)) != EOF) {
            if (isalnum(file_char))
                maxwidth++;
            else if (file_char == '\n') {
                if (size[0] < maxwidth)
                    size[0] = maxwidth;
                maxwidth = 0;
                size[1]++;
            }
        }
        if (size[0] < maxwidth)
            size[0] = maxwidth;

    }
    printf("%d %d", size[0], size[1]);

    return size;
}

int main(int argc, char** argv){
    char **flags = malloc(6 * sizeof *flags);
    flags[0] = "5";
    flags[1] = "y";
    flags[2] = "stdin";
    flags[3] = "stdout";
    flags[4] = "0";
    flags[5] = "1";
    int* size = Reader_CheckSize(flags);
}
