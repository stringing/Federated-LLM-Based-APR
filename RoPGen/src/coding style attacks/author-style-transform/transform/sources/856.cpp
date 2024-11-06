#include <bits/stdc++.h>
using namespace std;
char str[40005] = {0};
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    int len;
    for (len = 0; cin >> str[len]; len++); 
    len--;
    cout << (int)sqrt(len) + 1 << " ";
    int tmp = 0;
    char a = '0';
    for (int i = 0; i < len; i++) {
        if (str[i] == a) tmp++;
        else {
            cout << tmp << " ";
            a = str[i];
            tmp = 1;
        }
    }
    return 0;
}
