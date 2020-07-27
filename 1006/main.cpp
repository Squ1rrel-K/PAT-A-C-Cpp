#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
struct _node {
    char id[20];
    int h;
    int m;
    int s;
};

bool great(_node a, _node b) {
    if (a.h != b.h) return a.h > b.h;
    if (a.m != b.m) return a.m > b.m;
    return a.s > b.s;
}

int main() {
    int K;
    struct _node head = {
            .id={},
            .h=24,
            .m=60,
            .s=60

    };
    struct _node tail = {
            .id={},
            .h=0,
            .m=0,
            .s=0
    };

    scanf("%d",&K);
    while (K--) {
        struct _node tmp;
        scanf("%s", tmp.id);

        //找头
        scanf("%d:%d:%d", &tmp.h, &tmp.m, &tmp.s);
        if (great(head, tmp)) head = tmp;

        //找尾
        scanf("%d:%d:%d", &tmp.h, &tmp.m, &tmp.s);
        if (great(tmp, tail)) tail = tmp;
    }

    printf("%s %s", head.id, tail.id);
    return 0;
}



