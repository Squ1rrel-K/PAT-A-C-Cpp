#include <cstdio>

typedef long long LL;

int main() {
    int T, tCase = 1;
    scanf("%d", &T);
    while (T--) {
        LL a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        LL sum = a + b;
        bool res;

        if (a > 0 && b > 0 && sum < 0) res = true;
        else if (a < 0 && b < 0 && sum >=0) res = false;
        else if (sum > c) res = true;
        else res = false;
         if (res == true) printf("Case #%d: true\n", tCase++);
        else printf("Case #%d: false\n", tCase++);


    }
    return 0;
}
