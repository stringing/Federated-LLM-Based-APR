#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int num = 0, index, max;
    getline(cin, s);
    for (int i = 0; i <= s.size(); i++) {
        num++;
        max = num;
        if (s[i] == ' ') {
            num = 0;
            index = s[i] + 1;
        }
        if (num > max) {
            cout << max;
        } 
    }

    return 0;
}
