#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c;
    d = a * b;
    e = c - b;
    if (d % e == 0){
        cout << d / e - 6;
    }else{
        cout << d / e - 5;
    }
    return 0;
}
