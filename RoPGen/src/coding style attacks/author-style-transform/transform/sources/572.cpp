#include <string>
#include <iostream>
using namespace std;
int main() {
    string s,words[100];
    getline(cin, s);
    int index = 0,cnt = 0,a;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == ' ') {
        words[cnt] = s.substr(index,i - index);
        cnt++;
        index = i + 1;
            continue;
        }
        if (i = s.size() - 1) {
            words[cnt] = s.substr(index,i - index + 1);
        }
    }
    for (int j = 0;j <= cnt;j++) {
        if (words[j].size() >= words[j + 1].size()) {
            a = words[j];
            words[j + 1] = words[j];
        } else {
            a = words[j + 1];
        }
    }
    cout << a << endl;
        return 0;
}
