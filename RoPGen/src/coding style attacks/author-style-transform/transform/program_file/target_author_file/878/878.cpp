#include <algorithm>
#include <iostream>
using namespace std;
bool intcmp(int x, int y) {
    int s1 = 0;
    while (x) {
        s1 += x % 10;
        x /= 10;
    }
    int s2 = 0;
    while (y) {
        s2 += y % 10;
        y /= 10;
    }
    if (s1 != s2) {
        return s1 < s2;
    } else {
        return x < y;
    }
}

int a[10000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, intcmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
