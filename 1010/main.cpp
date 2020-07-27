#include <iostream>
#include <string>

using namespace std;
string n1, n2;
int tag, radix;
int res = -1;

int findRadix(string a, string b, int tag, int radix) {
    string target, value;
    if (tag == 1) target = b;value=a;
    if (tag == 2) target = a; value=b;

    while(value/radix!=0){

    }


}

int main() {
    cin >> n1 >> n2 >> tag >> radix;


    return 0;
}
