#include <bits/stdc++.h>
using namespace std;
int main() {
    string a[102];
    int n;
    cin >> n;
    int sum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    for (int i = 0; i <= n; i++) {
        cout << x << endl;
    }
    return 0;
}
