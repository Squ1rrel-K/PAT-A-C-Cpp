#include <cstdio>
#include <cstring>

int main() {
    int N, b, x = 1, y[40], cnt = 0, num = 0;

    //全置-1，方便后面监测
    memset(y, -1, sizeof(y));
    scanf("%d%d", &N, &b);

    //N =0
    if (N == 0) {
        printf("Yes\n%d", 0);
    }

    //N!=0
    else {
        while (x != 0) {
            //商
            x = N / b;
            //模
            y[cnt++] = N % b;
            N = x;
        }

        //检查y[]有几个用到的位置
        for (int i = 39; i >= 0; i--) {
            if (y[i] != -1) {
                num++;
            }
        }

        //颠倒一下给res[]
        int res[num];
        for (int i = 0; i < num; i++) {
            res[num - i - 1] = y[i];
        }

        //判断是否回文
        bool result =true;
        for (int i = 0; i < num; i++) {
            if (res[i] != res[num - 1 - i]) {
                result = false;
            }
        }

        //输出
        if(result==true){
            printf("Yes\n");
            for(int i = 0; i < num; i++){
                printf("%d",res[i]);
                if(i!=num-1) printf(" ");
            }
        }
        else{
            printf("No\n");
            for(int i = 0; i < num; i++){
                printf("%d",res[i]);
                if(i!=num-1) printf(" ");
            }
        }

    }
    return 0;
}
