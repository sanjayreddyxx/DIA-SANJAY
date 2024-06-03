#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;

        reversed = reversed * 10 + pop;
    }

    return reversed;
}

int main() {
    int x = 123;
    printf("Reversed: %d\n", reverse(x)); // Output: 321

    x = -123;
    printf("Reversed: %d\n", reverse(x)); // Output: -321

    x = 1534236469;
    printf("Reversed: %d\n", reverse(x)); // Output: 0 (overflow case)

    return 0;
}

