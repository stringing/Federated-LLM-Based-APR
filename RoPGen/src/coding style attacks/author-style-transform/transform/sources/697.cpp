#include <iostream>
using namespace std;
void f(long long n) {
    if(n == 12) {
        cout << "12, 6, 3, 12";
        return;
    } else if(n == 6) {
        cout << "6, 3, 12, 6";
        return;
    } else if(n == 3) {
        cout << "3, 12, 6, 3";
        return;
    }
    cout << n << ", ";
    if(n % 2 == 0) {
        f(n/2);
    } else if(n % 2 == 1) {
        f(n*3+3);
    }
}
int main() {
    int n;
    cin >> n;
    cout << n;
    f(n);
}
