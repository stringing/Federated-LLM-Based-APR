#include <bits/stdc++.h>
using namespace std;
long long n;
set<long long> a;
int main() {
    freopen("elevater.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> n;
    long long int sum = 0;
    long long x1, last = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (set<long long>::iterator it = a.begin(); it != a.end(); it++) {
        x1 = (*it);
        if (x1 > last) {
            sum += 5 * (x1 - last);
        }else {
            sum += 4 * (last - x1);
        }
        last = x1;
    }
    sum += a.size() * 3;
    sum += n * 2;
    if (x1 == 0) {
        cout << sum << endl;
        return 0;
    } else {
        sum += last * 4;
        cout << sum << endl;
    }
    return 0; 
}
