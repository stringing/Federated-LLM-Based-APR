#include <iostream>
using namespace std;
int  main () {
    double  n, a, b;
    cin >> n >> a >> b;
    double sum = (n * a - 600) / (b - a);
    cout << sum  << endl;
    return 0;
}
