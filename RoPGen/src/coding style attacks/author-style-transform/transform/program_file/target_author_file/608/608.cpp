#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200];
int sum(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return 0;
}                   
    bool cmp(int x, int y) {
        if (sum (x) != sum (y)) {
            return sum(x) < sum(y);
        } else {
            return x < y;
        }
    }    
    int main () {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }
