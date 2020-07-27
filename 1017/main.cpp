#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, k, curT, available, startH = 8, endH = 17;
double ave;
struct Cus {
    int h;
    int m;
    int s;
    int T;
    int realT;
};
vector<Cus> list;

bool cmp(Cus a, Cus b) {
    if (a.h == b.h) {
        if (a.m == b.m) {
            return a.s < b.s;
        }
        else {
            return a.m < b.m;
        }
    }
    else return a.h < b.h;
}


int main() {
    scanf("%d%d", &n, &k);
    available = k;
    int q[k];

    for (int i = 0; i < n; i++) {
        Cus tmp;
        scanf("%d:%d:%d %d", &tmp.h, &tmp.m, &tmp.s, &tmp.T);
        list.push_back(tmp);
    }

    //入队申请排序
    sort(list.begin(), list.end(), cmp);

    //入队
    while(!list.empty()) {
        Cus c = list[0];
        //没到8点，等待
        if (c.h < startH) {
            c.realT = startH - c.h;
            c.h = startH;
        }

        //超过17点，不予服务
        if (c.h > endH) {


        }

        //时间合理，尝试服务
        else {
            //有剩余窗口，可以服务
            if (available > 0) {
                available--;

                //找空窗口
                for (int j = 0; j < k; j++) {

                    //找到窗口
                    if (q[j] == 0) {
                        q[j] = c.T;

                        //服务
                    }
                }
            }

            //无剩余窗口，等待
            else {

            }

        }


    }
    return 0;
}
