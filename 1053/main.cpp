#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 105;
using namespace std;
struct Tree {
    vector<int> child;
    int w;

} tree[maxn];
int path[maxn];
int node, nonLeaf, targetW;

bool cmp(int a, int b) {
    return tree[a].w > tree[b].w;
}

void dfs(int index, int numNode, int sum) {
    //条件1
    if (sum > targetW) return;

    //条件2
    if (sum == targetW) {

        //不是子叶，查找失败
        if (tree[index].child.size() != 0) return;

        //是子叶，输出
        for (int i = 0; i < numNode; i++) {
            printf("%d", tree[path[i]].w);
            if (i != numNode - 1) printf(" ");
            else printf("\n");
        }
        return;
    }

    //递归遍历
    for (int i = 0; i < tree[index].child.size(); i++) {
        int child = tree[index].child[i];
        path[numNode] = child;
        dfs(child, numNode + 1, sum + tree[child].w);
    }

}

int main() {
    scanf("%d", &node);
    scanf("%d", &nonLeaf);
    scanf("%d", &targetW);

    for (int i = 0; i < node; ++i) {
        scanf("%d", &tree[i].w);
    }

    int id, k, child;
    for (int i = 0; i < nonLeaf; ++i) {
        scanf("%d", &id);
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            tree[id].child.push_back(child);
        }
        sort(tree[id].child.begin(), tree[id].child.end(), cmp);
    }

    path[0]=0;
    dfs(0,1,tree[0].w);

    return 0;
}
