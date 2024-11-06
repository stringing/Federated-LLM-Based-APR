#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if (s >= 'a' && s <= 'z') {
            s = 'a' + (s - 'a'- + z) % 26;
        } else if (s >= 'a' && s <= 'z') {
            s = 'a' + (s - 'a'- + z) % 26;
        }
    }
    return 0;
}
