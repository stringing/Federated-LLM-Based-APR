#include<iostream>
#define ll long long
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
ll sici (ll n) {
    return n * n;
}
ll addd (ll n) {
    for (ll i = 1; sici(i) <= n; i++) {
        if (sici(i) == n) {
            return i;
        }
    }
    return 0;
}
ll n;
int main () {
    freopen ("square.in", "r", stdin);
    freopen ("square.out", "w", stdout);
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            printf("0 0 0 %d", i);
            return 0;
        }
    }
    for (int i = 1; i * i <= n; i++) {
        for (int j = 1; j * j <= n; j++) {
            if (i * i + j * j == n) {
                printf("0 0 %d %d", i, j);
                return 0;
            }
        }
    }
    for (int i = 0; i * i <= n; i++) {
        for (int j = 1; j * j <= n; j++) {
            for (int k = 1; k * k <= n; k++) {
                ll x;
                if (addd(n - sici(i) - sici(j) - sici(k))) {
                    x = addd(n - sici(i) - sici(j) - sici(k));
                    printf("%d %d %d %lld", i, j, k, x);
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
