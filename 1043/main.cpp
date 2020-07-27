#include <cstdio>

int n;
const int maxn = 1005;
int pre[maxn], in[maxn], post[maxn];
struct Tree {
    int id;
    Tree *lc;
    Tree *rc;
};


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    return 0;
}
