#include <iostream>
using namespace std;   
int main() {
    double n,b,a,c;
    int d;
    cin >> n >> a >> b;
    c=n*a;
    d=(n*a-600)/(b-a)+1;
    cout << d << endl;
    return 0;
}

