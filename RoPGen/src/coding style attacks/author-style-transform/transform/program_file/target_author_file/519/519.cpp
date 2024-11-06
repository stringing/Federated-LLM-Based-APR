#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100001];
int tin, last;
set<long long> se;
int main() {
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (se.count(a[i])) {
            last = a[i - 1];
            tin += 2;
            continue;
        }
        if (a[i - 1] < a[i])
        {
            tin += (a[i] - a[i - 1]) * 5;
        }
        else
        {
            tin += (a[i - 1] - a[i]) * 4;
        }
        tin += 3;
        tin += 2;
        last = a[i];
        se.insert(a[i]);
    }
    tin += last * 4;
    cout << tin;
    return 0;
}
