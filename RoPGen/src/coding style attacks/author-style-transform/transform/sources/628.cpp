#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = b - a;
    if (n * a < 600){
        cout << "0";
    }
    double t = (n * a - 600) / m;
    cout << t;
    return 0;
}
