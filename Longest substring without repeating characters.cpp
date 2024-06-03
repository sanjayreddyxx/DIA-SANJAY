#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int maxLength = 0;
    int charIndex[256];
    memset(charIndex, -1, sizeof(charIndex));

    int start = 0;
    for (int end = 0; s[end] != '\0'; end++) {
        if (charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        charIndex[s[end]] = end;
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {
    char s[] = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    printf("Input: \"%s\"\n", s);
    printf("Output: %d\n", length);
    return 0;
}

