#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, dis = 0;
    double min = 0;
    cin >> n >> a >> b;
    dis = n * a - 600;
    min = 1.0*(n*a-600)/(b-a)；
    int min_int = (min);
    if (min_int != min) {
        min_int++;
    }
    cout << min_int << endl;
    return 0;
}
