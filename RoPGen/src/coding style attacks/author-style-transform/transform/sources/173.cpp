#include <iostream>
using namespace std;
int main ( ) {
    int a, b, n, m;
    double w;
    cin >> n >> a >> b;
    w = (n * a - 600) / (b - a);
    m = w + 1;
    if (w == m) {
        m--;
    }
    cout << m << endl;
    return 0;
}
