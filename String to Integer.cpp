#include <stdio.h>
#include <limits.h>

int myAtoi(char *s) {
    int sign = 1;
    long long result = 0;
    int i = 0;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        if (sign == 1 && result > INT_MAX)
            return INT_MAX;
        else if (sign == -1 && -result < INT_MIN)
            return INT_MIN;
        i++;
    }

    return sign * result;
}

int main() {
    char s1[] = "42";
    printf("Input: %s\nOutput: %d\n\n", s1, myAtoi(s1)); 

    char s2[] = " -42";
    printf("Input: %s\nOutput: %d\n\n", s2, myAtoi(s2));

    char s3[] = "4193 with words";
    printf("Input: %s\nOutput: %d\n", s3, myAtoi(s3)); 

    return 0;
}
