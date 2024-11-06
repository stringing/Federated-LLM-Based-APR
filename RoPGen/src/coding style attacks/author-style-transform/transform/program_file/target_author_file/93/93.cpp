#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("elevator.in" , "r" , stdin);
    freopen ("elevator.out" , "w" , stdout);
    long long n , x;
    map <long long , int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    auto last = a.end();
    long long sum = 0;
    sum += last->first * 9 + a.size() * 3 + n * 2 + 9;
    cout << sum << endl;
    return 0;
}
