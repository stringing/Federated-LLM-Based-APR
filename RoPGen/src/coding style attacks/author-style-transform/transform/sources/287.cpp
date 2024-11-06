#include <iostream>
using namespace std;
int main() {
    int n, s, y, a;
    char x;
    cin >> n >> y >> s;
    a = y;
    while (n--) {
        cin >> x;
        if ( y == 0 ) {
            if ( x >= '0' && x <= '9' ) {
                x = ( x - '0' + s ) % 10 + '0';       
            }else if ( x >= 'A' && x <= 'Z' ) {
                x = ( x - 'A' + s ) % 26 + 'A';
            }else if ( x >= 'a' && x <= 'z') {
                x = ( x - 'a' + s ) % 26 + 'a';
            }
            cout << x;
            y = a;
        }else{
            cout << x;
        }
        y--;
    }
    return 0;
}
