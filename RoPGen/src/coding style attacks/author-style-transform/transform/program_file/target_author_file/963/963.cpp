#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int max = 0;
    int sum = 0;
    string a;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (sum > max) {
                max = sum;
                i -= sum;
                a.replace(0, a.size(), "");
                while (sum--) {
                    a += s[i];
                    i++;
                }
            }
            sum = 0;
        } else {
            sum ++;
        }
    }
    cout << a << endl;
    return 0;
}
