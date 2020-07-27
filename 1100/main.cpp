#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
map<int, string> first = {
        {0,  "tret"},
        {1,  "jan"},
        {2,  "feb"},
        {3,  "mar"},
        {4,  "apr"},
        {5,  "may"},
        {6,  "jun"},
        {7,  "jly"},
        {8,  "aug"},
        {9,  "sep"},
        {10, "oct"},
        {11, "nov"},
        {12, "dec"}
};

map<int, string> second = {
        {0,  "tret"},
        {1,  "tam"},
        {2,  "hel"},
        {3,  "maa"},
        {4,  "huh"},
        {5,  "tou"},
        {6,  "kes"},
        {7,  "hei"},
        {8,  "elo"},
        {9,  "syy"},
        {10, "lok"},
        {11, "mer"},
        {12, "jou"}
};




int main() {
    int N;
    scanf("%d\n", &N);
    while (N--) {
        string str;
        getline(cin, str);

        //人话转火星文
        if (isdigit(str[0])) {
            int num = 0;

            //string 转 int
            for (int i = 0; i < str.length(); i++) {
                num = num * 10 + (str[i] - '0');
            }


            int sh = num / 13;
            int yu = num % 13;

            if (second[sh] == "tret") {
                cout << first[yu] << "\n";
            }
            else {
                cout << second[sh] << " " << first[yu] << "\n";
            }


        }

            //火星文转人话
        else {
            int ind = 0;
            string fir, sec;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ' ') {
                    ind = i;
                    break;
                }
                else ind = -1;

            }

            //两位数
            if (ind != -1) {
                for (int i = 0; i < ind; i++) {
                    sec += str[i];
                }
                for (int i = ind + 1; i < str.length(); i++) {
                    fir += str[i];
                }

                int res;
                for (map<int, string>::iterator it = second.begin(); it != second.end(); it++) {
                    if (it->second == sec) {
                        res += (it->first) * 13;
                    }
                }

                for (map<int, string>::iterator it = first.begin(); it != first.end(); it++) {
                    if (it->second == fir) {
                        res += it->first;
                    }
                }
                cout << res << "\n";

            }
            else {
                int res=0;
                for (map<int, string>::iterator it = second.begin(); it != second.end(); it++) {
                    if (it->second == str) {
                        res += it->first*13;
                    }
                }
                cout << res << "\n";
            }

        }


    }


    return 0;
}
