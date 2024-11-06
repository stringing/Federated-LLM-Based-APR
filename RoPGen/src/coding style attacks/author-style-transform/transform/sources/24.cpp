#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    int cnt = 0;
    sum = a * n;
    int t = 0;
    while (t++) {
        cnt = cnt + b;
        sum = sum + a;
        if (cnt - sum <= 600) {
            cout << t << endl;
            break;
        }
    }
    return 0;
}
