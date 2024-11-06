#include <iostream>
using namespace std;   
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = (n * b - 600) / (b - a) - 15;
    cout << x << endl;
    return 0;
}
