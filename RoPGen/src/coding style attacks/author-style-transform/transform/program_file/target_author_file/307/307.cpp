#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int a0, b0; 
    if (a < 0) {
        cout <<" " ;
    } else {
        a0 = a;
    }
    if (b < 0) {
        cout << " ";
    } else {
        b0 = b;
    }
    
    if (a0 > b0) {
        cout << b << " " << a << endl;
    
    } else if (b0 == a0 && b < a){
        cout << b << " " << a << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}
