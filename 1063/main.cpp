#include <cstdio>
#include <set>

using namespace std;
int N, K, num1, num2;

void countSimilarity(set<int> a, set<int> b) {
    int total = b.size(), same = 0;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        if (b.find(*it) != b.end()) same++;
        else total++;
    }
    printf("%.1f%%\n", same * 100.0 / total);

}

int main() {
    scanf("%d", &N);
    set<int> inp[N];

    //N个set遍历
    for (int i = 0; i < N; i++) {

        //获取M个数
        int M;
        scanf("%d", &M);

        //每个set的M个数遍历
        for (int j = 0; j < M; j++) {
            int num;
            scanf("%d", &num);
            inp[i].insert(num);

        }
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &num1);
        scanf("%d", &num2);
        countSimilarity(inp[num1 - 1], inp[num2 - 1]);

    }

    return 0;
}
