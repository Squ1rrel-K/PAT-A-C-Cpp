#include <iostream>
#include <string>

using namespace std;
int sum = 0;
string num;
string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"

};

int main() {
    cin >> num;

    for (int i = 0; i < num.length(); i++) {
        sum += num[i] - '0';
    }

    string res =to_string(sum);
    int i = 0;
    while (i != res.length()) {
        if (i != res.length() - 1) {
            cout << str[res[i] - '0'] << " ";
        }
        else {
            cout << str[res[i] - '0'] << endl;
        }

        i++;

    }


    return 0;
}
