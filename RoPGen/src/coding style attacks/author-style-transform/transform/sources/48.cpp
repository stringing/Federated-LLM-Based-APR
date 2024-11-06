#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string correct, ans[101];
int main() {
    int a = 0;
    string s, t;
    getline(cin, s);
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            t = s;
            t.replace(0, s.find(' '), "");
            if (s.find(' ') != string::npos) {
                s.replace(s.find(' '), s.size() - s.find(' '), "");
                if (s.size() > a) {
                    a = s.size();
                }
            }
        } else {
            s = t;
            s.replace(0, t.find(' '), "");
            if (t.find(' ') != string::npos) {
                t.replace(t.find(' '), t.size() - t.find(' '), "");
                if (t.size() > a) {
                    a = t.size();
                }
            }
        }
    }
    cout << a;
    return 0;
}
