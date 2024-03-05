#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removeExtraSpaces(char *str) {
    int len = strlen(str);
    int i, j;
    int spaceCount = 0;

    for (i = 0; i < len; i++) {
        if (isspace(str[i])) {
            spaceCount++;
        }
        else {
            break;
        }
    }

    for (j = 0; j < len - spaceCount; j++) {
        str[j] = str[j + spaceCount];
    }

    len -= spaceCount;

    for (i = 0, j = 0; i < len; i++) {
        if (isspace(str[i])) {
            while (isspace(str[i + 1])) {
                i++;
            }
        }
        str[j++] = str[i];
    }

    str[j] = '\0';
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
    fclose(inputFile);

    removeExtraSpaces(str);

    fputs(str, outputFile);
    fclose(outputFile);

    return 0;
}
