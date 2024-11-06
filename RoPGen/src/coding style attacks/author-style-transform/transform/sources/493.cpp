#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    int a[1005][1005], b = 0, n, i = 0, j = 0;
    string c;
    cin >> n;
    c = n;
    cout << c.size();
    n = c.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                b++;
            } else {
                cout << b << " ";
                b = 1;
            }
        }
    }
    cout << b;
    return 0;
}
