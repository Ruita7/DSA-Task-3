#include <stdio.h>

long long sumNatural(int n) {
    if (n == 0) {
        return 0;               /* Base case */
    }
    return n + sumNatural(n - 1);
}

int main(void) {
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Sum of the first %d natural numbers = %lld\n",
           n, sumNatural(n));
    return 0;
}
