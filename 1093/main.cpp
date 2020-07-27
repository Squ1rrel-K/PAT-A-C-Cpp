#include <cstdio>
#include <cstring>

char arr[100005];
int p[100005], t[100005];
int length;
long long sum;

int main() {
    scanf("%s", arr);
    length = strlen(arr);


    //首位测试
    if (arr[0] == 'P') p[0] = 1;
    else p[0] = 0;

    for (int i = 1; i < length; i++) {
        if (arr[i] == 'P') p[i] = p[i - 1] + 1;
        else p[i] = p[i - 1];

    }

    //尾位测试
    if (arr[length - 1] == 'T') t[length - 1] = 1;
    else t[length - 1] = 0;

    for (int i = length - 2; i >= 0; i--) {
        if (arr[i] == 'T') t[i] = t[i + 1] + 1;
        else t[i] = t[i + 1];
    }

    for (int i = 0; i < length; i++) {
        if (arr[i] == 'A') {
            sum += p[i] * t[i];
        }

    }
    printf("%d", sum % 1000000007);

    return 0;
}
