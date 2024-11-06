#include <iostream>
#include <algorithm>
using namespace std;
int sum(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
}
int main() {
    int n, a[102];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, sum);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
