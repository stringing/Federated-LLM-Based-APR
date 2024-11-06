#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int a0, b0; 
    if (a < 0) {
    }if(a < b){ 
     cout << a0 * (-1) << endl;  
    } else {
        a0 = a;
    }
    if (b < 0) {
     if(b < a)   
      cout << b0 * (-1) << endl;   
    } else {
        b0 = b;
    }
    
    if (a < b || b > a) {
        cout << b << " " << a << endl;
    
    } else if (a > b || b < a){
        cout << b << " " << a << endl;
    } else {
        cout << a << " " << b << endl;
    }
    return 0;
}
