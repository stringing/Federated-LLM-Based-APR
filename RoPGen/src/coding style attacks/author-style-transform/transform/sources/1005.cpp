#include <iostream>
using namespace std;
int main() {
    int n, a, b, d;
    cin >> n >> a >> b;
     d = (a * n - 600) / (b - a);
    if ((a * n - 600) != d * (b - a)) {
        cout << d + 1;
    }
    cout << d << endl;
}
