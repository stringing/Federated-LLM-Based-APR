#include <iostream>
using namespace std;
int main() {
    int n , a , b;
    cin >> n >> a >> b;
    int min;
    min = 1.0 * (n * a - 600) / b - a;
    int min_int = int (min);
    if (min_int != min) {
        min_int ++;
        cout << min_int;
    }else {
        cout << min;
    }
    return 0;
}
