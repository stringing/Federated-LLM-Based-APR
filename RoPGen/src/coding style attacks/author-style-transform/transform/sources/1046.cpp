#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    getline(cin, s);
    int r, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ans = 0;
            r = r + 1;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        
    }
    return 0;
}
