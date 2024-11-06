#include <iostream>
#include <string>
using namespace std;
int main() {
    int a = 0, index = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            a = 0;
        } else {
            a++;
        }
    }
    return 0;
}
