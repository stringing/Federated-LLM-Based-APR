#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        cin >> i;
        if (i % y == 0) {
            if (s >= 'A' && s <= 'Z') {
                s = (s - 'A' + z) % 26 + 'A';
            } else if ( s >= 'a' && s <= 'z') {
                s = (s - 'a' + z) % 26 + 'a';
            } else if (s >= '0' && s <= '9') {
                s = (s - '0' + z) % 10 + '0';
            }
        } else if (i % y != 0) {
            s = s;
        }
        cout << s;
    }
    return 0;
}
