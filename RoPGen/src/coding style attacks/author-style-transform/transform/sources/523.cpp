#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        cnt++;
        if (cnt % y == 0) {
            if (s >= 'A') && s <= 'Z') {
                cout << (char)((s - 65 + 2) % 26 + 65);
            } else if  (s >= 'a' && s <= 'Z') {
                cout << (char)((s - 97 + 2) % 26 + 97); 
            } else {
                cout << (char)((s - '0' + 2) % 10 + '0'); 
            }
        } else {
            cout << s;
        }
    }
    return 0;
}
