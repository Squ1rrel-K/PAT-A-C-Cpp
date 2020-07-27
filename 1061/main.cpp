#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char str1[65], str2[65], str3[65], str4[65];
    char code[3];
    char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int cnt = 0;
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);
    int min1 = min(strlen(str1), strlen(str2));
    int min2 = min(strlen(str3), strlen(str4));

    //拿到前两个code
    for (int i = 0; i < min1; i++) {
        if (cnt == 0 && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'Z') {
            code[cnt++] = str1[i];
            continue;
        }
        else if (cnt == 1 && str1[i] == str2[i] &&
                 ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9'))) {
            code[cnt++] = str1[i];
            break;
        }

    }

    //拿到第三个code
    for (int i = 0; i < min2; i++) {
        if (str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z'))) {
            code[cnt] = i + '0';
            break;
        }
    }

    //处理code
    //周几
    printf("%s ", week[code[0] - 'A']);

    //小时
    if (code[1] >= 'A' && code[1] <= 'N') {
        printf("%02d:", code[1] - 'A' + 10);

    }
    else {
        printf("%02d:", code[1] - '0');
    }

    //分钟
    printf("%02d", code[2] - '0');

    return 0;
}
