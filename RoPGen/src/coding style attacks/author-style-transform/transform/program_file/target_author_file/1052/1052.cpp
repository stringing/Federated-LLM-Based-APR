#include <string>
#include <iostream>
using namespace std;
int main() {
    string s, max = "";
    getline(cin, s);

    string a = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            a += s[i];
        } else {
            if (a.size() > max.size()) {
                max = a;
            }
            a = "";
        }
    }
    cout << max << endl;
    return 0;
}
