#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
int N, K, course, chNum;
string id;
map<string, vector<int> > info;

int main() {
    scanf("%d%d", &N, &K);

    //K个课程遍历
    while (K--) {
        scanf("%d", &course);
        scanf("%d", &chNum);
        for (int i = 0; i < chNum; i++) {
            cin >> id;
            info[id].push_back(course);
        }

        map<string, vector<int> >::iterator it;
        for (it = info.begin(); it != info.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }


    }

    while (N--) {
        cin >> id;
        cout << id << " " << info[id].size();
        int size = info[id].size();
        for (int i = 0; i < size; i++) {
            cout << " " << info[id][i];
        }
        cout << "\n";
    }

    return 0;
}
