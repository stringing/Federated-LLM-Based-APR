#include <algorithm>
#include <iostream>
using namespace std;
bool intcmp(int x, int y[10001]) {
    int b[10001];
    for(int i = 1; i < x; i++){
        while(y[i] != 0){
            b[i] += y[i] % 10;
            y[i] = y[i] / 10;
        }
    }
    for(int i = 0; i < x; i++){
        return b[i] < b[i + 1] || (b[i] == b[i + 1] && y[i] < y[i + 1]);
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
