#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    double t;
    cin >> n >> a >> b;
    t = (n * a - 600) / (b - a);
    cout << (int)t + 1 << endl;
    return 0;
}
