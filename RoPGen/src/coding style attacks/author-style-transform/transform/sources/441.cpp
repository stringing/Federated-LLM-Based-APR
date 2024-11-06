#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        char s;
        cin >> s;
        if (s >= 'A' && s <= 'Z'){
            s = 'A' + (s - 'A' + z) % 26;
        }else if(s >= 'a' && s <= 'z'){
            s = 'a' + (s - 'a' + z) % 26;
        }else if(s >= '0' && s <= '9'){
            s = '0' + (s - '0' + z) % 10;
        }
        cout << s;}
    }
    return 0;
}
