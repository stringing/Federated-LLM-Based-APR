#include <iostream>
using namespace std;
int main() {
    int x, y, z ,a;
    char s;
    cin >> x >> y >> z;
    int i = 1;
    while (x--) {
        cin >> s;
        if (i % y == 0){
            if ( s >= 'A' &&  x <= 'Z'){
                s = 'A' + (s - 'A' + z) % 26;
            }else if ( s >= 'a' && x <= 'z'){
                s = 'a' + (s - 'a' + z) % 26;
            }else if (s >= '0' && x <='9'){
                s = '0' + (s - '0' + z) % 10;
            }
            i = i + 1;
            cout << s;
        }else{
        i = i + 1;
        cout << s;
        }
    }
    return 0;
}
