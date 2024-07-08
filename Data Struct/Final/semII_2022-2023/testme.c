#include <stdio.h>

long testMe(long n);

int main() {
    long result;

    result = testMe(5);
    printf("\nResult = %ld\n", result);

    return 0;
}

long testMe(long n) {
    if (n == 0 || n == 1) {
        printf("%ld ", n);
        return n;
    } else {
        return testMe(n - 1) + testMe(n - 2);
    }
}
