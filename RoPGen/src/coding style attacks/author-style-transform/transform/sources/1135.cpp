#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n, a, b, k;
    cin >> n >> a >> b;
    k = (n * a - 600) / (b - a);
    if (floor(k / k) != k) {
        k += 1;
    }
    cout << k;
    return 0;
}
