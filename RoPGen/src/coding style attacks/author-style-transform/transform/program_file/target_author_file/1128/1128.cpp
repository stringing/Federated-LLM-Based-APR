#include <iostream>
#include <string>
using namespace std;
int main() {
    int num = 0;
    string s, n;
    getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                num = 0;
            }else {
                num++;
            }
        }
    cout << s << endl;
    return 0;
}

