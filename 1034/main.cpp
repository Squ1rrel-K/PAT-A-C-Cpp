#include <iostream>
#include <map>

using namespace std;

const int maxn = 2020;
int G[maxn][maxn] = {0};//边权
int weight[maxn] = {0};//点权
bool vis[maxn] = {false};
int n, m, t, numOfAll;
string a, b;

//将数字与名字对应: 1->AAA, AAA->1
map<string, int> stringToInt;
map<int, string> intToString;

//帮派记录 头子->人数
map<string, int> gangs;

int getId(string str) {
    //str出现过
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    }

        //没出现过
    else {
        stringToInt[str] = numOfAll;
        intToString[numOfAll] = str;
        return numOfAll++;
    }
}


void DFS(int u, int &head, int &numMember, int &totalValue) {
    numMember++;
    //访问顶点u
    vis[u] = true;

    //头子易主
    if (weight[u] > weight[head]) head = u;

    //枚举所有顶点
    for (int i = 0; i < numOfAll; ++i) {
        //u能访问i
        if (G[u][i] > 0) {
            //更新总边权
            totalValue += G[u][i];

            //断边，防止环的二次遍历
            G[u][i] = G[i][u] = 0;

            //i未被访问
            if (vis[i] == false) {
                DFS(i, head, numMember, totalValue);
            }
        }

    }
}

void DFSTrave() {
    //遍历顶点
    for (int i = 0; i < numOfAll; i++) {
        //初始化变量
        int head = i, numMember = 0, totalValue = 0;
        //尚未被访问
        if (vis[i] == false) {
            //从该顶点DFS
            DFS(i, head, numMember, totalValue);
            //是否满足阈值
            if (numMember > 2 && totalValue > m) {
                gangs[intToString[head]] = numMember;
            }

        }

    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> t;

        //id与名字对应
        int id1 = getId(a);
        int id2 = getId(b);

        //点权增加
        weight[id1] += t;
        weight[id2] += t;

        //边权增加
        G[id1][id2] += t;
        G[id2][id1] += t;

    }
    //DFS遍历
    DFSTrave();

    //输出
    cout << gangs.size() << "\n";
    for (map<string, int>::iterator it = gangs.begin(); it != gangs.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}
