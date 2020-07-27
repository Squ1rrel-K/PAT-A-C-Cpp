#include <cstdio>
#include <vector>

using namespace std;

int k, curNum, maxSum = -1, tmpSum = 0, tmpLeft, tmpRight, maxLeft, maxRight;
vector<int> arr;

int main() {
    scanf("%d", &k);
    maxLeft = 0;
    maxRight = k - 1;

    //闭区间
    tmpLeft =-1  ;
    tmpRight = -1;
    while (k--) {
        scanf("%d", &curNum);
        arr.push_back(curNum);

        //读入非负
        if (curNum >= 0) {
            //利好，肯定要
            tmpSum += curNum;
            tmpRight++;

            //更新最大
            if (tmpSum > maxSum) {
                maxSum = tmpSum;
                maxLeft = tmpLeft;
                maxRight = tmpRight;
            }
            if (tmpSum == maxSum) {
                if (tmpLeft < maxLeft) {
                    maxSum = tmpSum;
                    maxLeft = tmpLeft;
                    maxRight = tmpRight;
                }

            }
        }

            //读入负数
        else {
            //num 没有做贡献
            if (curNum + tmpSum < 0) {
                tmpSum = 0;
                tmpRight++;
                tmpLeft = tmpRight+1;
            }
            else {
                tmpSum += curNum;
                tmpRight++;
            }
        }


    }
    int allNeg = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            allNeg = 0;
            break;
        }
    }
    if (allNeg == 1) {
        printf("0 %d %d", arr[maxLeft], arr[maxRight]);
    }
    else {
        if (maxSum > -1)printf("%d %d %d", maxSum, arr[maxLeft], arr[maxRight]);
        else printf("0 %d %d", arr[maxLeft], arr[maxRight]);
    }


    return 0;
}
