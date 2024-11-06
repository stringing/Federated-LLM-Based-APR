#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("zip.in" , "r" , stdin);
    freopen ("zip.out" , "w" , stdout);
    int n = 0;
    string a = "" , s;
    while (cin >> a) {
        s += a;
        n++;
    }
    cout << n << ' ';
    char flag = s[0];
    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != flag) {
            cout << cnt << ' ';
            flag = s[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    return 0;
}
