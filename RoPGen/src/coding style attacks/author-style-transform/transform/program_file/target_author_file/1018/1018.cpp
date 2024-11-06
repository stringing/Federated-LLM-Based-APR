#include <bits/stdc++.h>
using namespace std;
int sum(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}
bool cmp(int x, int y) {
    if (sum(x) != sum(y)) {
        return sum(x) < sum(y);
    } else {
        return x < y;
    }
}
int main() {
    string a[102];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
