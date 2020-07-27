#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
struct info {
    char id[15];
    int grade;
    int fRank;
    int lNum;
    int lRank;
};

bool cmp(struct info a, struct info b) {
    if (a.grade != b.grade) return a.grade > b.grade;
    else return strcmp(a.id, b.id) < 0;

}

int main() {

    //读入考场数
    scanf("%d", &N);
    struct info stu[30005];

    //数组哨兵
    int head = 1;

    //学生数量
    int cnt = 0;

    //考场循环
    for (int i = 1; i <= N; i++) {
        //读入每个考场人数
        int K = 0;
        scanf("%d", &K);
        cnt += K;

        //考生id，成绩，考场号赋值
        for (int j = head; j < head + K; j++) {
            scanf("%s", stu[j].id);
            scanf("%d", &stu[j].grade);
            stu[j].lNum = i;

        }
        //考场内成绩排序
        sort(&stu[head], &stu[head + K], cmp);

        //考场内排名赋值
        stu[head].lRank = 1;
        int rank = 1;
        for (int j = head + 1; j < head + K; j++) {
            rank++;
            if (stu[j].grade == stu[j - 1].grade) stu[j].lRank = stu[j - 1].lRank;
            else stu[j].lRank = rank;
        }
        head += K;
    }

    //整个学校成绩排名
    sort(&stu[1], &stu[head], cmp);

    //整个学校排名赋值
    stu[1].fRank = 1;
    int rank = 1;
    for (int j = 2; j < head; j++) {
        rank++;
        if (stu[j].grade == stu[j - 1].grade) stu[j].fRank = stu[j - 1].fRank;
        else stu[j].fRank = rank;
    }

    //输出
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%s %d %d %d\n", stu[i].id, stu[i].fRank, stu[i].lNum, stu[i].lRank);
    }

    return 0;
}


