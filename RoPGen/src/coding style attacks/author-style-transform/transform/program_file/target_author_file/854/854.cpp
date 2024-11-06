#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if ((i + 1) % y == 0) {
            if (s >= 'a' && s <= 'z') {
                s = (char)('a' + (s - 'a' + z) % 26);
            } else if (s >= 'A' && s <= 'Z') {
                s = (char)('A' + (s - 'A' + z) % 26);
                
            } else if (s >= '0' && s <= '9') {
                s = (char)('0' + (s - '0' + z) % 10);
            }
        }
    
    }
    cout << s;
    return 0;
}
