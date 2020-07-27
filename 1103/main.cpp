#include <cstdio>
#include <vector>

using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> tmp, best, fac;

int power(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}


void cal(int index, int nowK, int sum, int facSum) {
    //满足要求的序列
    if (nowK == k && sum == n) {
        //字典数更大
        if (facSum > maxFacSum) {
            maxFacSum = facSum;
            best = tmp;
        }
        return;
    }

    //非法位置返回
    if (sum > n || nowK > k) return;
    //不选0
    if (index >= 1) {
        //选这个index
        tmp.push_back(index);
        cal(index, nowK + 1, sum + fac[index], facSum + index);
        tmp.pop_back();

        //不选
        cal(index - 1, nowK, sum, facSum);
    }


}

int main() {
    scanf("%d%d%d", &n, &k, &p);

    //fac 初始化，省时间;
    int i = 0;
    while (power(i, p) <= n) {
        fac.push_back(power(i, p));
        i++;
    }

    cal(fac.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) printf("Impossible\n");
    else {
        printf("%d = %d^%d",n,best[0],p);
        for(int i=1;i<best.size();i++){
            printf(" + %d^%d",best[i],p);
        }
    }


    return 0;
}
