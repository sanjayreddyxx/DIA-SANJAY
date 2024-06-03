#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);
    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true; 
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*' && dp[0][j - 2]) {
            dp[0][j] = true;
        }
    }

   
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    char s1[] = "aa";
    char p1[] = "a";
    printf("Input: s = \"%s\", p = \"%s\"\nOutput: %s\n\n", s1, p1, isMatch(s1, p1) ? "true" : "false"); 

    char s2[] = "aa";
    char p2[] = "a*";
    printf("Input: s = \"%s\", p = \"%s\"\nOutput: %s\n\n", s2, p2, isMatch(s2, p2) ? "true" : "false"); 

    char s3[] = "ab";
    char p3[] = ".*";
    printf("Input: s = \"%s\", p = \"%s\"\nOutput: %s\n", s3, p3, isMatch(s3, p3) ? "true" : "false");

    return 0;
}
