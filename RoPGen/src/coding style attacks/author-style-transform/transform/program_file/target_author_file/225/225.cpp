#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int a0, b0; 
    if (a < 0) {
        cout << a * -1 = a0; 
    } else {
        a0 = a;
    }
    if (b < 0) {
        cout << b * -1 = b0;
        
    } else {
        b0 = b;
    }
    
    if (a * -1 == b * -1) {
        cout << b << " " << a << endl;
    
    } else if (a * -1 > b * -1 && a * -1 < b * -1){
        cout << b << " " << a << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}
