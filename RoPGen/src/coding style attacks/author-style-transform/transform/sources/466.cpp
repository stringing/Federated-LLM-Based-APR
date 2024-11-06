#include <iostream>
using namespace std;
int main() {
    int x, y, z,cnt = 0;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        cnt++;
        if (cnt % y == 0) {
            if(s >= 'a' && s <= 'z') {
            s = (char)('a' +(s - 'a' + x) % 26);
        } else if (s >= 'A' && s <= 'z') {
            s = (char)('A' + (s - 'A' + x) % 26);
        } else if (s >= '0' && s <= '9'){
            s =(char) ('0' + (s - '0' + x) % 10);
        }
        }
    }
    return 0;
}
