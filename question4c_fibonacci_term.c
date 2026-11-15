#include <stdio.h>

/* This version numbers the first term as F(0) = 0. */
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n;

    printf("Enter term position (starting from 0, maximum 93): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 93) {
        printf("Please enter a valid position from 0 to 93.\n");
        return 1;
    }

    printf("F(%d) = %llu\n", n, fibonacci(n));
    return 0;
}
