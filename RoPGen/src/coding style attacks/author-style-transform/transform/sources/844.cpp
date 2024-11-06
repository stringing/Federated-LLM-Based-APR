#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int dis = n * a - 600;
    double min;
    min = dis / ( b - a );
    int min_int = (int)min;
    if (min_int != min) {
        min_int += 1;
    }
    cout << min_int << endl;
    return 0;
}
