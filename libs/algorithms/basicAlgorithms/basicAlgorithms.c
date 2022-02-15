#include <math.h>
#include <memory.h>
#include "basicAlgorithms.h"

long long max2(long long a, long long b) {
    return a > b ? a : b;
}

long long min2(long long a, long long b) {
    return a < b ? a : b;
}

long long max3(const long long a, const long long b, const long long c) {
    return max2(max2(a, b), c);
}

void swap(void *v1, void *v2, size_t size) {
    char *t[size];
    memcpy(t, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, t, size);
}

void sort2(int *a, int *b) {
    if (*a > *b)
        swap(a, b, sizeof(int));
}

void sort3(int *a, int *b, int *c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}

int isPrime(const long long n) {
    if (n == 2)
        return 1;
    if (n % 2 == 0 || n == 1)
        return 0;
    int sqrtN = sqrt(n);
    for (long long i = 3; i <= sqrtN; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

