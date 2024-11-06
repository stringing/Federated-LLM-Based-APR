#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int d = n * a - 600;
    int min = d / (b - a);
    int min_int = int(min);
    if (min_int != min) {
        min_int++;
    }
    cout << min_int << endl;
    return 0;
}
