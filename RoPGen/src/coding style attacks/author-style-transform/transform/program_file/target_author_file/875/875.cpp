#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    long long a[100005], n, maxn;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    maxn = a[n - 1];
    int ptr = 0, time = 0;
    for (int i = 1; i <= maxn; i++) {
        time += 5;
        if (a[ptr] == i) {
            time += 3;
            while (a[ptr] == i) {
                time += 2;
                ptr ++;
            }
        }
    }
    cout << time << endl;
}
