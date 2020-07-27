#include <cstdio>
#include <cstring>

int main() {
    char str[85];
    scanf("%s", str);
    int N = strlen(str);
    int n1 = (N + 2) / 3;
    int n3 = n1;
    int n2 = N - n1 - n3 + 2;
    char res[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            res[i][j] = ' ';
        }
    }

    for (int i = 0; i < n1; i++) {
        res[i][0] = str[i];

    }
    for (int i = 0; i < n2; i++) {
        res[n1 - 1][i] = str[i + n1 - 1];

    }

    for (int i = 0; i < n1; i++) {
        res[n1 - i - 1][n2 - 1] = str[n1 + n2 - 2 + i];
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%c", res[i][j]);
        }
        printf("\n");

    }

    return 0;
}
