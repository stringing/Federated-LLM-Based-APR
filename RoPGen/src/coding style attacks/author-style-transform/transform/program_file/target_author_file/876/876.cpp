#include <iostream>
using namespace std;   

int main() {
    int n, a, b , c;
    cin >> n >> a >> b;
    c = (n * a) / (b - a);
    c = c - 1;
    cout << c << endl;
    return 0;
}

