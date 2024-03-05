#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changeExtension(char *filename, const char *newExt) {
    char *extPos = strrchr(filename, '.');

    if (extPos != NULL) {
        strcpy(extPos + 1, newExt);
    }
    else {
        strcat(filename, ".");
        strcat(filename, newExt);
    }
}

int main(void) {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("could not open input.txt\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("could not open output.txt\n");
        fclose(inputFile);
        return 1;
    }

    char filename[1001];
    fgets(filename, sizeof(filename), inputFile);
    fclose(inputFile);

    char newExt[] = "html";
    changeExtension(filename, newExt);

    fputs(filename, outputFile);
    fclose(outputFile);

    return 0;
}