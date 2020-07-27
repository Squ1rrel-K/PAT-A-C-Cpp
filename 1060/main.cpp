#include <iostream>
#include <string>

using namespace std;
int N;
string A, B;

struct num {
    string str;
    int e = 0;
} num1, num2;

//去除无意义的0
string removeZeros(string str) {
    while (str.length() > 0 && str[0] == '0') {
        str.erase(str.begin());
    }
    return str;
}

struct num deal(struct num tmp, int n) {
    string s = tmp.str;
    int k = 0;

    //如果.开头，说明是0.xxxx型
    if (s[0] == '.') {

        //去除首位'.'，变成xxxxxxxx
        s.erase(s.begin());

        //去除'.'后面所有的0
        while (s[0] == '0' && s.length() > 0) {
            s.erase(s.begin());
            tmp.e--;
        }
    }
    else {

        while (k < s.length() && s[k] != '.') {
            k++;
            tmp.e++;

        }
        if (k < s.length()) {
            s.erase(s.begin() + k);
        }
        if (s.length() == 0) {
            tmp.e = 0;
        }
        int num = 0;
        k = 0;
        string res;

        while (num < n) {
            if (k < s.length()) res += s[k++];
            else res += '0';
            num++;
        }
        tmp.str = res;
    }

    return tmp;

}

int main() {
    cin >> N >> A >> B;
    A = removeZeros(A);
    num1.str = A;
    num1 = deal(num1, N);

    B = removeZeros(B);
    num2.str = B;
    num2 = deal(num2, N);
    if (num1.str == num2.str && num1.e == num2.e) {
        cout << "YES 0."<<num1.str<<"*10^"<<num1.e<<endl;
    }
    else{
        cout << "No 0."<<num1.str<<"*10^"<<num1.e<<" ";
        cout << "0."<<num2.str<<"*10^"<<num2.e<<endl;

    }


    return 0;
}


