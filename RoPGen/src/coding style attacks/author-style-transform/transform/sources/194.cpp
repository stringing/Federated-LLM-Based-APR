#include <bits/stdc++.h>
using namespace std;
int a[10], b[10], ans = 2147483647;
int n;
string to_bin(int dec) {
    vector<int> v;
    while (dec != 0) {
        v.push_back(dec % 2);
        dec /= 2;
    }
    string binary = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        binary = binary + to_string(v[i]);
    }
    while (binary.size() < n) binary = "0" + binary;
    return binary;
}
int search1(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') num++;
    }
    return num;
}
void dfs(int depth) {
    for (int i = 0; ; i++) {
        if (to_bin(i).size() > n) break;
        if (search1(to_bin(i)) != depth) continue;
        string tmp = to_bin(i);
        int tmp1 = 1, tmp2 = 0;
        for (int j = 0; j < n; j++) {
            if (!(tmp[j] - '0')) continue;
            tmp1 *= a[j];
            tmp2 += b[j];
        }
        ans = min(ans, abs(tmp1 - tmp2));
    }
    return;
}
int main() {
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    return 0;
}
