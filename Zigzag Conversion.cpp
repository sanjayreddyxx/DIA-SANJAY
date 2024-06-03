#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char** rows = (char*)malloc(numRows * sizeof(char));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0'; 
    }

    int currRow = 0;
    int goingDown = 0;

    for (int i = 0; i < len; i++) {
        strncat(rows[currRow], &s[i], 1);

        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }

        currRow += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]); 
    }

    free(rows); 

    return result;
}

int main() {
    char s1[] = "PAYPALISHIRING";
    int numRows1 = 3;
    printf("Input: %s, numRows: %d\nOutput: %s\n\n", s1, numRows1, convert(s1, numRows1));

    char s2[] = "PAYPALISHIRING";
    int numRows2 = 4;
    printf("Input: %s, numRows: %d\nOutput: %s\n\n", s2, numRows2, convert(s2, numRows2));

    char s3[] = "A";
    int numRows3 = 1;
    printf("Input: %s, numRows: %d\nOutput: %s\n", s3, numRows3, convert(s3, numRows3));

    return 0;
}
