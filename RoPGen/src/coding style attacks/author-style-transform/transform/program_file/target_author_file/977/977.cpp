#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 1;
    while (x--) {
        cin >> s;
        if(i % y == 0 && s >= 'a' && s <= 'z') {
        s = (s - 'a' + z) % 26 + 'a';   
        } else if(i % y == 0 && s >= 'A' && s <= 'Z') {
            s = (s - 'A' + z) % 26 + 'A';
        } else if(i % y == 0 && s >= '0' && s <= '9') {
            s = (s - '0' + z) % 10 + '0';
        }
        cout << x;
    }
    return 0;
}
