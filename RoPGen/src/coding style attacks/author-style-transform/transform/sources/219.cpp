#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    int n;
    cin >> n;
    int a[100005];
    int d;
    int sumsec = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    sort(a, a + n);
    
    sumsec += a[0] * 5;
    sumsec += 5;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            d = a[i + 1] - a[i];
            
            sumsec += d * 5;
            
            sumsec += 5;
        }
    }
    sumsec += a[n - 1] * 4;
    cout << sumsec << endl;
    return 0;
}
