#include <iostream>
#include <algorithm>
using namespace std;
int n,a[200];
int sum(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        s /= 10;
    }
     return s;
}
bool cmp (int x,int y) {
    int sx = sum(x),sy = sum(y);
    if (sx == sy) {
        return x < y;
    } else {
        return sx < sy;
    }
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
sort(a,a + n,cmp);
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
     return 0;
}
