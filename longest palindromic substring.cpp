#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expandAroundCenter(char* s, int left, int right, int* start, int* maxLength) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    left++;
    right--;
    int len = right - left + 1;
    if (len > *maxLength) {
        *start = left;
        *maxLength = len;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, maxLength = 1;
    for (int i = 0; i < n; i++) {
        expandAroundCenter(s, i, i, &start, &maxLength);
        expandAroundCenter(s, i, i + 1, &start, &maxLength);
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    return result;
}

int main() {
    char s1[] = "babad";
    printf("Input: %s\nOutput: %s\n", s1, longestPalindrome(s1)); 

    char s2[] = "cbbd";
    printf("Input: %s\nOutput: %s\n", s2, longestPalindrome(s2));

    return 0;
}
