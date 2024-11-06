#include <iostream>
using namespace std;   

int main() {
    int n, a, b, min_int;
    cin >> n >> a >> b;
    double min;
    min *= 1.0;
    min = (a * n - 600) / (b - a);
    min_int = (a * n - 600) / (b - a);
    if (min == min_int) {
        cout << min << endl;
    } else {
        min_int++;
        cout << min_int << endl;
    }
    return 0;
}

