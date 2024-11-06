#include <iostream>
using namespace std;
int main() {
    int n, a, b, d;
    cin >> n >> a >> b;
    d = (a * n - 600) / (b - a);
    cout << d << endl;
    return 0;
}
