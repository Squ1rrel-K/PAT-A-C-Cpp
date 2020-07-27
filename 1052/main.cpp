#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct List {
    int address;
    int key;
    int next;
    bool flag;

} list[maxn];

int N, FirAddress;

bool cmp(List a, List b) {

    //无效节点
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;

    }
    else {
        return a.key < b.key;
    }
}

int main() {
    //初始化
    for (int i = 0; i < maxn; i++) {
        list[i].flag = false;
    }

    //输入
    scanf("%d%d", &N, &FirAddress);
    int address, key, next;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &address, &key, &next);
        list[address].address = address;
        list[address].key = key;
        list[address].next = next;
    }

    //缕一缕链表
    int count = 0;
    for (int p = FirAddress; p != -1; p = list[p].next) {
        list[p].flag = true;
        count++;
    }

    //空列表
    if (count == 0) {
        printf("0 -1");
    }

        //非空
    else {
        //排序
        sort(list, list + maxn, cmp);

        //输出
        printf("%d %05d\n", count, list[0].address);
        for (int i = 0; i < count; i++) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", list[i].address, list[i].key, list[i + 1].address);
            }
            else {
                printf("%05d %d -1\n", list[i].address, list[i].key);

            }


        }
    }

    return 0;
}
