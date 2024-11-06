#include <cstdio>
#include <algorithm>
using namespace std;
long long floor[100005], ans = 0;
int main() {
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", floor[i]);
    }
    sort(floor + 1, floor + n + 1);
    long long now = floor[n];
    ans += now * 5; 
    for (int i = n; i >= 1; i--) {
        long long temp = floor[i];
        ans += 3;
        do {
            ans += 2;
            i--;
        } while (floor[i] == floor[i - 1]); 
        now = floor[i];
        ans += temp * 4;
    }
    printf("%lld", ans);
    return 0;
}
