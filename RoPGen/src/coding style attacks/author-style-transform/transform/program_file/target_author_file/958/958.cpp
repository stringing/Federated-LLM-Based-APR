#include <iostream>
using namespace std;
int main() {
    int n, a, b, m;
    double d, s, sh, c;
    cin >> n >> a >> b;
    d = n * a;
    s = d - 600;
    m = d - 600;
    c = b - a;
    m = s / c;
    sh = s / c;
    if (m != (int)sh) {
        m++;
    }
    cout << m;
    return 0;
}
