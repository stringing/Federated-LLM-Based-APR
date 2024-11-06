#include <algorithm>
#include <iostream>
using namespace std;
bool intcmp(int x, int y) {
        if(x.size()!=y.size()){
                return x.size()<y.size();
        }
    return x<y;
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
