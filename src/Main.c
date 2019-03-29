#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void Flags_Interpreter(char **argv, int argc, char **flags) {
    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "--gen") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-' && i < argc - 1) {
                flags[0] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--gen\' została podana bez wartości, domyślna wartość to 5 \n");
            }
        } else if (strcmp(argv[i], "--print") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[1] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--print\' została podana bez wartości, domyślna wartość to y \n");
            }
        } else if (strcmp(argv[i], "--input") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[2] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--input\' została podana bez wartości, dane zostaną pobrane ze standardowego wejścia \n");
            }
        } else if (strcmp(argv[i], "--output") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[3] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--output\' została podana bez wartości, wyniki zostaną wypisane na standardowe wyjście \n");
            }
        } else if (strcmp(argv[i], "--dead") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[4] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--dead\' została podana bez wartości, domyślna wartość to \'0\' \n");
            }
        } else if (strcmp(argv[i], "--alive") == 0) {
            if (i != argc - 1 && *argv[i + 1] != '-') {
                flags[5] = argv[++i];
            } else {
                fprintf(stderr,
                        "Flags_Interpreter: Flaga \'--alive\' została podana bez wartości, wyniki zostaną pobrane ze standardowego wejścia \n");
            }
        }
    }
}

void Check_Flags(char **flags) {
    if (atoi(flags[0]) > 1000) {
        printf("Check_Flags: Nieprawidłowa wartość flagi \'--gen\', domyślna wartość to 5 \n");
        flags[0] = "5";
    } else {
        for (int i = 0; i < strlen(flags[0]); i++) {
            if (isdigit(*(flags[0] + i)) == 0) {
                printf("Check_Flags: Nieprawidłowa wartość flagi \'--gen\', domyślna wartość to 5 \n");
                flags[0] = "5";
                break;
            }
        }
    }

    if (strcmp(flags[1], "y") != 0 && strcmp(flags[1], "n") != 0) {
        flags[1] = "y";
        fprintf(stderr, "Check_Flags: Nieprawidłowa wartość flagi \'--print\', domyślna wartość to y \n");
    }


}

int main(int argc, char **argv) {
    char **flags = malloc(6 * sizeof *flags);
    flags[0] = "5";
    flags[1] = "y";
    flags[2] = "std in";
    flags[3] = "stdout";
    flags[4] = "0";
    flags[5] = "1";
    Flags_Interpreter(argv, argc, flags);
    for (int i = 0; i < 6; i++) {
        printf("%s \n", flags[i]);
    }
    /*
    printf("%c \n druga:    %c \n", *(flags[0]), *(flags[0] + 1));

    char c = "f";
    int i = atoi(c);


     */
    printf("AFTER \n \n");
    Check_Flags(flags);
    for (int i = 0; i < 6; i++) {
        printf("%s \n", flags[i]);
    }


    return 0;

}

