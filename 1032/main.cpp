#include <cstdio>

const int maxn = 100010;
struct List {
    char data;
    int next;
    bool flag;
} list[maxn];
int a1, a2, N;

int main() {
    scanf("%d%d%d", &a1, &a2, &N);

    //初始化静态链表
    for (int i = 0; i < maxn; i++) {
        list[i].flag = false;
    }

    //输入所有数据
    int address, next;
    char data;
    for (int i = 0; i < N; i++) {
        scanf("%d %c %d", &address, &data, &next);
        list[address].data = data;
        list[address].next = next;
    }

    //遍历list 1
    int p;
    for (p = a1; p != -1; p = list[p].next) {
        list[p].flag = true;
    }
    //遍历list 2
    //陷阱，p一定有个相同值-1
    for (p = a2; p != -1; p = list[p].next) {
        if (list[p].flag == true) break;

    }

    if (p != -1) printf("%05d\n", p);

    else printf("-1\n");
    return 0;
}
