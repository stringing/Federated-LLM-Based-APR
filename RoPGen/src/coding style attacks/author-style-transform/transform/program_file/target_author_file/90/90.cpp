#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, temp = 0, flag = 0, time = 0, sum = 0;
    cin >> n >> a >> b;
    temp = n * a;
    for ( int i = 1; i <= n ; i++) {
        sum += b - a;
        time ++;
        if ( b + sum == a - 600) {
            break;
        }
    }
    cout << time;
    return 0;
}
