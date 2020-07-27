#include <cstdio>

const int MAX = 1005;
double arr[MAX] = {};

int main() {
    int K, N, count = 0;
    double aN;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        scanf("%lf", &aN);
        arr[N] += aN;
    }

    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        scanf("%lf", &aN);
        arr[N] += aN;
    }

    for (int i = 0; i < MAX; i++) {
        if (arr[i] != 0) count++;
    }
    printf("%d", count);

    for (int i = MAX-1; i >= 0; i--) {
        if (arr[i] != 0) printf(" %d %.1f", i, arr[i]);

    }

    return 0;
}
