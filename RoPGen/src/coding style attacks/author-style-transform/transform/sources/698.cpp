#include <iostream>
using namespace std;
int main() {
    int x, y, z, a, b;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        a = x;
        b = 1;
        cin >> s;
        if (b % y == 0){
            if (s >= 'a' && s <= 'z'){
                s = (s - 'a' + 3) % 26 +'a';
            }
            if (s >= 'A' && s <= 'Z'){
                s = (s - 'A' + 3) % 26 +'A';
            }
            if(s >= '0' && s <= '9'){
                s = (s - '0' + 3) % 10 + '0';
            }
        }
        b += 1;
        cout << s;
    }
    return 0;
}
