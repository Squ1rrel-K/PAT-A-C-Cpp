#include <cstdio>
const int N = 54;
char huaSe[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N + 1], end[N + 1], next[N + 1];


int main() {
    int K;
    scanf("%d", &K);

    //读入洗牌规则
    for (int i = 1; i <= N; i++) {
        scanf("%d", &next[i]);
    }

    //牌组初始化
    for (int i = 1; i <= N; i++) {
        start[i] = i;
    }

    //执行k次洗牌
    for (int j = 1; j <= K; j++) {
        for (int i = 1; i <= N; i++) {
            end[next[i]] = start[i];
        }
        for (int i = 1; i <= N; i++) {
            start[i] = end[i];
        }

    }

    //输出
    for (int i = 1; i <= N; i++) {
        printf("%c%d", huaSe[(start[i]-1) / 13], (start[i]-1) % 13 + 1);
        if (i != N) printf(" ");
    }
    return 0;
}
