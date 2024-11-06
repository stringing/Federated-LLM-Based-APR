#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (i <= 100){
        cout << i << " ";
        i = i += 2;
    }
    while (x--) {
        cin >> s;
        if (s >= 'A' && s <= 'Z'){
            s = (char)('A' + (s - 'A' + z) % 26);
        }else if (s >= 'a' && s <= 'z'){
            s = (char)('a' + (s - 'a' + z) % 26);
        }else if (s >= '0' && s <= '9'){
            s = (char)('0' + (s - '0' + z) % 26);
        }
        cout << s;
    }
    return 0;
}
