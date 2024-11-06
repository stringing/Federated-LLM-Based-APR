#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int sum (int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
bool cmp (int a, int b) {
    if (sum(a) != sum(b)) {
        return sum(a) < sum(b);
    }
    return a > b;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag = a[n - 1];
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        if (a[i] == flag) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
