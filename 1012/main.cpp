#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct Stu {
    int id;
    int c;
    int m;
    int e;
    int a;
    int rankC, rankM, rankE, rankA;
    int bestRank;
    char bestSub;
} c;
vector<struct Stu> info;
int n, m, id;

bool cmpByC(struct Stu a, struct Stu b) {
    return a.c > b.c;
}

bool cmpByM(struct Stu a, struct Stu b) {
    return a.m > b.m;
}

bool cmpByE(struct Stu a, struct Stu b) {
    return a.e > b.e;
}

bool cmpByA(struct Stu a, struct Stu b) {
    return a.a > b.a;
}

int minN(int a, int b) {
    if (a > b) return b;
    else return a;
}

int main() {
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d%d%d%d", &c.id, &c.c, &c.m, &c.e);
        c.a = (c.c + c.m + c.e) / 3;
        info.push_back(c);
    }


    sort(info.begin(), info.end(), cmpByA);
    info[0].rankA = 1;
    for (int i = 1; i < info.size(); i++) {
        if (info[i].a < info[i - 1].a) {
            info[i].rankA = info[i - 1].rankA + 1;
        }
        else info[i].rankA = info[i - 1].rankA;
    }


    sort(info.begin(), info.end(), cmpByC);
    info[0].rankC = 1;
    for (int i = 1; i < info.size(); i++) {
        if (info[i].c < info[i - 1].c) {
            info[i].rankC = info[i - 1].rankC + 1;
        }
        else info[i].rankC = info[i - 1].rankC;
    }


    sort(info.begin(), info.end(), cmpByM);
    info[0].rankM = 1;
    for (int i = 1; i < info.size(); i++) {
        if (info[i].m < info[i - 1].m) {
            info[i].rankM = info[i - 1].rankM + 1;
        }
        else info[i].rankM = info[i - 1].rankM;
    }


    sort(info.begin(), info.end(), cmpByE);
    info[0].rankE = 1;
    for (int i = 1; i < info.size(); i++) {
        if (info[i].e < info[i - 1].e) {
            info[i].rankE = info[i - 1].rankE + 1;
        }
        else info[i].rankE = info[i - 1].rankE;
    }

    for (int i = 0; i < info.size(); i++) {
        int minNum = minN(info[i].rankA, minN(info[i].rankC, minN(info[i].rankM, info[i].rankE)));
        if (minNum == info[i].rankE) {
            info[i].bestRank = info[i].rankE;
            info[i].bestSub = 'E';
        }
        if (minNum == info[i].rankM) {
            info[i].bestRank = info[i].rankM;
            info[i].bestSub = 'M';
        }
        if (minNum == info[i].rankC) {
            info[i].bestRank = info[i].rankC;
            info[i].bestSub = 'C';
        }
        if (minNum == info[i].rankA) {
            info[i].bestRank = info[i].rankA;
            info[i].bestSub = 'A';
        }
    }

    //找id能否匹配
    for (int i = 0; i < m; i++) {
        scanf("%d", &id);
        for (int j = 0; j < info.size(); j++) {
            if (info[j].id == id) {
                printf("%d %c\n", info[j].bestRank, info[j].bestSub);
                break;
            }
            else if (j == info.size() - 1) printf("N/A\n");

        }

    }
    return 0;
}
