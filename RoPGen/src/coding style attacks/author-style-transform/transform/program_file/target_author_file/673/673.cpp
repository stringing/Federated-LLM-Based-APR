#include <iostream>
using namespace std;
int main() {
    double n, a, b, k;
    cin >> n >> a >> b;
    k = (n * a - 600) / (b - a);
    cout << k;
    return 0;
}
