#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
char s[200010], ans[200010];
int slen;
string trans(int x) {
    string r;
    while (x > 0) {
        r += '0' + x % 10;
        x /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    cin >> s;
    string t;
    int pre = -1;
    bool flag = false;
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        t += s[i];
        ++len;
        if ((i + 1) % 8 != 0) {
            continue;
        }
        if (flag && t[0] != '0') {
            cout << "Error" << endl;
            return 0;
        }
        if (t.substr(0, 3) == "101") {
            int tmp = 0;
            for (int k = 3; k < 8; k++) {
                tmp = tmp * 2 + t[k] - '0';
            }
            if (tmp > 25) {
                cout << "Error" << endl;
                return 0;
            }
            ans[slen] = tmp +'A';
            ++slen;
        } else if (t.substr(0, 3) == "111") {
            ans[slen] = ' ';
            ++slen;
        } else if (t[0] == '0') {
            int tmp = 0;
            for (int k = 0; k < 8; k++) {
                tmp = tmp * 2 + t[k] - '0';
                flag = false;
            }
            if (!flag) {
                flag = true;
                pre = -1;
            }
        }
        else {
            cout << "Error" << endl;
            return 0;
        }
        t = "";
    }
    if (flag || len % 8 != 0) {
        cout << "Error" << endl;
    } else {
        for (int j = 0; j < slen; j++) {
            cout << ans[j];
        }
    }
    return 0;
}
