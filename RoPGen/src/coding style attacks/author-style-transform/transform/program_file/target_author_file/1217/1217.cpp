#include <iostream>
using namespace std;   
int main() {
    int n, a, b, s;
    double d;
    cin >> n >> a >> b;
    b -= a;
    n *= a;
    n -= 600;
    d = n / b;
    if (n % b > 0){
        cout << d;
    }else{
        s = d;
        s += 1;
        cout << s << endl;
    }
    return 0;
}
