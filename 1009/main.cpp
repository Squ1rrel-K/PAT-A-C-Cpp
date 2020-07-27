#include <cstdio>

int const subMax = 1005;
int const MAX = 1100000;
double arr1[subMax] = {};
double arr2[subMax] = {};
double arr[MAX] = {};

int main() {
    int K, N, cnt = 0;
    double aN;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        scanf("%lf", &aN);
        arr1[N] += aN;
    }

    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        scanf("%lf", &aN);
        arr2[N] += aN;
    }

    for (int i = 0; i < subMax; i++) {
        for (int j = 0; j < subMax; j++) {
            int q = i + j;
            arr[q] += arr1[i] * arr2[j];
        }

    }

    for (int i = 0; i < MAX; i++) {
        if (arr[i] != 0) cnt++;
    }

    printf("%d", cnt);

    for (int i = MAX - 1; i >= 0; i--) {
        if (arr[i] != 0) printf(" %d %.1f", i, arr[i]);
    }

    return 0;
}
