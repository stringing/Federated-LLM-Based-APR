#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    while (x--) {
        cin >> s;
        if (y >= 'a' && y <= 'z') {
            s = char ('a' + (s - 'a' + z) % 26);
        } else if (y >= 'A' && y <= 'Z') {
            s = char ('A' + (s - 'A' + z) % 26);
        } else if (y >= '0' && y <= '9') {
            s = char ('0' + (s - '0' + z) % 10);
        }
        cout << s;
    }
    return 0;
}
