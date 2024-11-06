#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[20005];
int main() {
    freopen("shelf.in", "r", stdin);
    freopen("shelf.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += a[i];
        if(tmp >= m) {
            cout << tmp - m;
            break;
        }
    }
    return 0;
}

