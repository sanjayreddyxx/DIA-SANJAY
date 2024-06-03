#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(int x) {
    if (x < 0) 
        return false;

    char str[12]; 
    sprintf(str, "%d", x);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int x1 = 121;
    printf("Input: %d\nOutput: %s\n\n", x1, isPalindrome(x1) ? "true" : "false"); 

    int x2 = -121;
    printf("Input: %d\nOutput: %s\n\n", x2, isPalindrome(x2) ? "true" : "false");

    int x3 = 10;
    printf("Input: %d\nOutput: %s\n", x3, isPalindrome(x3) ? "true" : "false"); 

    return 0;
}
