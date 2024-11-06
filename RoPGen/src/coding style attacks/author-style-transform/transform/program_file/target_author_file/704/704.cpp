#include <iostream>
using namespace std;   

int main() {
    int n, m, k, d;
    cin >> n >> m >> k;

    d = ( n * m - 600 ) / ( k - m );
    cout << d << endl;
    return 0;
}

