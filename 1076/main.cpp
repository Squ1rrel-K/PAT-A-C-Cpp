#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1005;
int G[maxn][maxn];///G[a][b]表示 b是a的粉丝 b -> a，遍历时从 a 遍历
int level[maxn];
bool vis[maxn] = {false};


int n, l, m, k, user;

int BFS(int curUser, int follower) {

    //传播第0层
    level[curUser] = 0;

    queue<int> q;
    q.push(curUser);
    vis[curUser] = true;

    //遍历未结束 && 层数不高于l
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        //遍历所有其它顶点
        for (int v = 1; v <= n; v++) {

            //未访问过，访问合法，层数合法
            if (vis[v] == false && G[u][v] == 1 && level[u] + 1 <= l) {
                q.push(v);
                vis[v] = true;
                follower++;
                level[v] = level[u] + 1;
            }
        }

    }
    return follower;
}


int main() {
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> m;
        if (m != 0) {
            for (int j = 1; j <= m; j++) {
                int num;
                cin >> num;
                G[num][i] = 1;
            }
        }


    }

    cin >> k;
    while (k--) {
        memset(vis,false, sizeof(vis));
        cin >> user;
        int follower = 0;
        int res = BFS(user, follower);
        cout << res << "\n";
    }
    return 0;
}
