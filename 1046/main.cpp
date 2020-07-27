#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, sum = 0, M, l, r;
int arr[100001], dis[100001];

int main() {
    //数组初始化
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        dis[i] = sum;
    }

    //判断距离
    scanf("%d", &M);
    while (M--) {
        int distance = 0;
        scanf("%d", &l);
        scanf("%d", &r);

        //出现4 1 这种就颠倒一下
        if (r < l) swap(l, r);

        for (int i = l; i <= r - 1; i++) {
            distance += arr[i];
        }
        int res = dis[r - 1] - dis[l - 1];
        printf("%d\n", min(res, sum - res));


    }

    return 0;
}
