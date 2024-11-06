#include <bits/stdc++.h>
using namespace std;
int tag = 1;
int a[999999];

int find(int x) {
    for (int i = 1; i <= tag - 1; i++) {
        if (a[i] == x) {
            return 1;
        }
    }
    return 0;
}

int fly(int y) {
    if (find(y)) {
        cout << y;
        return 0;
    }
    a[tag] = y;
    tag++;
    cout << y << " ";
    if (y % 2 == 0) {
        fly(y / 2);
    } else {
        fly((y - 1) * 3 + 6);
    }
}

int main() {
    int n;
    cin >> n;
    fly(n);
    return 0;
}
