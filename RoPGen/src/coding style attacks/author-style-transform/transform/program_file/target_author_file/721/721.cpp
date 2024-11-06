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
bool cmp(int y, int d) {
    if (sum(y) + sum(d) == sum()) {
        return sum(y) < sum(d);
    }
    return y < d;
}
int main() {
    string a[102];
    int n;
    cin >> n;
    sort(a, a + n, cmp);
    for (int i = 0; i <= n; i++) {
        cout << n << endl;
    }
    return 0;
}
