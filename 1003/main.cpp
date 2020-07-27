#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxn = 501;
const int INF = 0x3fffffff;
int n, road, c1, c2, G[maxn][maxn], d[maxn], pWeight[maxn], mostPeople = -1, numOfSD = 0, shortestD = INF;
bool vis[maxn] = {false};
vector<int> pre[maxn];
vector<int> best, tmp;


void Dij(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        //找离u最近的，能访问的
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }


}

void DFS(int v) {
    //边界
    if (v == c1) {
        tmp.push_back(v);
        int people = 0, distance = 0;
        for (int i = 0; i < tmp.size(); i++) {
            people += pWeight[tmp[i]];
        }
        for (int i = 0; i < tmp.size() - 1; i++) {
            distance += G[tmp[i]][tmp[i + 1]];
        }

        if (distance < shortestD) {
            shortestD = distance;
            best.clear();
            best.push_back(people);
        }

        else if (distance == shortestD) {
            best.push_back(people);
        }

        tmp.pop_back();
        return;

    }

    tmp.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tmp.pop_back();

}

int main() {
    scanf("%d%d%d%d", &n, &road, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pWeight[i]);
    }

    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < road; i++) {
        int u, v, eWeight;
        scanf("%d%d%d", &u, &v, &eWeight);
        G[u][v] = G[v][u] = eWeight;
    }

    Dij(c1);
    DFS(c2);

    for (int i = 0; i < best.size(); i++) {
        if (best[i] > mostPeople) mostPeople = best[i];
    }
    numOfSD = best.size();
    printf("%d %d\n", numOfSD, mostPeople);

    return 0;
}

