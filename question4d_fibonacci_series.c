#include <stdio.h>

void printFibonacci(int remaining, unsigned long long first,
                    unsigned long long second) {
    if (remaining == 0) return; /* Base case */

    printf("%llu ", first);
    printFibonacci(remaining - 1, second, first + second);
}

int main(void) {
    int n;

    printf("How many Fibonacci terms should be displayed? ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 94) {
        printf("Please enter a number from 0 to 94.\n");
        return 1;
    }

    printf("Fibonacci series: ");
    printFibonacci(n, 0, 1);
    printf("\n");

    return 0;
}
