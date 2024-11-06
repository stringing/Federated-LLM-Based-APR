#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    double min;
    cin >> n >> a >> b;
    double s = n * a - 600;
    double v = b - a;
    min = s / v;
    cout << (min) << endl;
    return 0;
}
