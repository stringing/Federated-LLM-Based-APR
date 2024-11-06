#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int a0, b0; 
    if (a < 0) {
        
    } else {
        a0 = a;
    }
    if (b < 0) {
        
    } else {
        b0 = b;
    }
    
    if (b < a) {
        cout << b << " " << a << endl;
    
    } else if (a > b){
        cout << b << " " << a << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}
