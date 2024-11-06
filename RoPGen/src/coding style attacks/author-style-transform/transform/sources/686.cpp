#include <bits/stdc++.h>
using namespace std;
string s;
stringstream ans;
int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    cin >> s;
    if (s.size() % 8) {
        cout << "Error\n";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            cout << "Error\n";
            return 0;
        }
    }
    bool flag = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1') {
            ans << ' ';
        } else if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') {
            int val = 0;
            for (int k = i + 3; k <= i + 7; k++) {
                val = 2 * val + s[k] - '0';
                if (val < 26) {
                    ans << char('A' + val);
                } else {
                    flag = 0;
                    break;
                }
            }
        } else if (s[i] == '0' && i + 8 < s.size() && s[i + 8] == '0') {
            int v1 = 0, v2 = 0;
            for (int k = i; k < i + 7; k++) v1 = 2 * v1 + s[k] - '0';
            for (int k = i + 8; k < i + 15; k++) v2 = 2 * v2 + s[k] - '0';
            ans << v1 + v2;
            i += 8;
        } else {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << ans.str() << endl;
    } else {
        cout << "Error\n";
    }
    return 0;
}
