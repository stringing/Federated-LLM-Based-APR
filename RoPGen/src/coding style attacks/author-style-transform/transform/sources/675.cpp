#include <iostream>
using namespace std;   

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    double min = 0;
    min = (a * n - 600) / (b - a);
    if (min % 1 != 0) {
        min = min / 1;
        min = min + 1;
        cout << min << endl;
    } else {
        cout << min << endl;
    }
    return 0;
}

