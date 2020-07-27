#include <cstdio>
#include <vector>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char name[40005][5];
bool cmp(const int a, const int b){
    return strcmp(name[a], name[b]) < 0;
}
vector<int> st[2505];
int main()
{
    int n, k, tn, t;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i){
        scanf("%s%d", name[i], &tn);
        for (int j = 0; j < tn; ++j){
            scanf("%d", &t);
            st[t].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i){
        printf("%d %d\n", i, st[i].size());
        sort(st[i].begin(), st[i].end(), cmp);
        for (vector<int>::iterator it = st[i].begin(); it != st[i].end(); ++it){
            printf("%s\n", name[*it]);
        }
    }
    return 0;
}