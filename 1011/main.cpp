#include <cstdio>
#include <algorithm>

int main() {
    char res[3] = {'W', 'T', 'L'};

    double product = 1;
    int i = 3;
    while (i--) {
        double tmpRate = 0, rate;
        int index = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%lf", &rate);
            if (rate > tmpRate) {
                tmpRate = rate;
                index = i;
            }

        }
        product *= tmpRate;
        printf("%c ", res[index]);
    }
    printf("%.2f", (product * 0.65 - 1) * 2);


    return 0;
}
