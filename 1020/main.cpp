#include <cstdio>
#include <queue>

using namespace std;
struct tree {
    int data;
    tree *lc;
    tree *rc;
};
const int maxn = 50;
int pre[maxn], in[maxn], post[maxn];
int n;

tree *create(int postL, int postR, int inL, int inR) {
    if (postL > postR)return NULL;

    tree *root = new tree;
    root->data = post[postR];

    int i;
    for (i = inL; i <= inR; i++) {
        if (in[i] == post[postR]) break;

    }
    int numLeft = i - inL;
    root->lc = create(postL, postL + numLeft - 1, inL, i - 1);
    root->rc = create(postL + numLeft, postR - 1, i + 1, inR);
    return root;

}

int num = 0;

void BFS(tree *root) {
    queue<tree *> q;
    q.push(root);
    while (!q.empty()) {
        tree *now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if (num < n) printf(" ");
        if (now->lc != NULL) q.push(now->lc);
        if (now->rc != NULL) q.push(now->rc);

    }

}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    tree *root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
