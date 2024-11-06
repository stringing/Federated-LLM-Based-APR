#include <bits/stdc++.h>
using namespace std;
int sum(int sum) {
    int cnt = 0;
    while (sum > 0) {
        cnt += sum % 10;
        sum /= 10;
    }
    return cnt;
}
bool cmp(int x, int y) {
    return sum(x) <= sum(y);
}
int main() {
    int n;
    cin >> n;
    int a[101];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
