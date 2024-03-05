#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapAdjacentCharacters(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i += 2) {
        if (str[i] != ' ') {
            char temp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = temp;
        }
    }
}

int main(void) {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("Could not open input.txt\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("Could not open output.txt\n");
        fclose(inputFile);
        return 1;
    }

    char str[1001];
    fgets(str, sizeof(str), inputFile);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

     if (len % 2 != 0) {
        len--;
    }

    swapAdjacentCharacters(str);

    fputs(str, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
