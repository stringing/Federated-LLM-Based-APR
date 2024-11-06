#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if (y>='a' && y<='z'){
            s=(s - 'a'+z) % 26 + 'a' ; 
        }else if (y>='A' && y<='Z' ) {
            s=(s - 'A' +z) % 26 + 'A' ;
        }else if (y>='0' && y<='9'){
            s=(s - '0'+z) % 26 + '0';
        }
        cout << s;
        
    }
    return 0;
}
