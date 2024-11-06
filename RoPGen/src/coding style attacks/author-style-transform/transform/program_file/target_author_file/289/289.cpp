#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int a0, b0; 
    if (a < 0) {
        a = 0 + a;
        
    } else {
        a0 = a;
    }
    if (b < 0) {
        b = 0 + b;
        
    } else {
        b0 = b;
    }
    
    if (b < a) {
        cout << b << " " << a << endl;
    
    } else if (b = a){
        cout << b << " " << a << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}
