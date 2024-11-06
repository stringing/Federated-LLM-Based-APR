#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 105;
const int maxn = 5005;

int dp[maxn];

struct Meat {
    int price, value;
} meat[MAXN];

struct Vegetable {
    int price, value;
} vegetable[MAXN];

int main() {
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {
        cin >> meat[i].price >> meat[i].value;
    }
    for(int i = 1; i <= m; i++) {
        cin >> vegetable[i].price >> vegetable[i].value;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = vegetable[i].price; j <= x; j++) {
            dp[j] = max(dp[j - vegetable[i].price] + vegetable[i].value, dp[j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = meat[i].price; j <= x; j++) {
            if(dp[j] != 0) {
                dp[j] = max(dp[j - meat[i].price] + meat[i].value, dp[j]);
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
