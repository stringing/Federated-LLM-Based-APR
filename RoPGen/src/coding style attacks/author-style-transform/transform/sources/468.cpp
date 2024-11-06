#include <iostream>
using namespace std;
int main() {
    int x, y, z, cnt = 0;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        cnt++;
        if (cnt % y == 0){
            if(s >= 'a' && s <= 'z') {
                s = (s - 'a' + z) % 26 + 'a';
            } else if (s >= '0' && s <= '9') {
                s = (s - '0' +z) % 10 + '0';
            }
        }
        cout << s;
    }
    return 0;
}
