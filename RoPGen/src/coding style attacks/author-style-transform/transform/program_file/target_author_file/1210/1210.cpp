#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i <= sqrt(n); i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                for (int d = 0; d <= k; d++) {
                    if (i * i + j * j + k * k + d * d== n) {
                        cout << d << " " << k << " " << j << " " << i;
                    }
                }
            }
        }
    }
    return 0;
}

