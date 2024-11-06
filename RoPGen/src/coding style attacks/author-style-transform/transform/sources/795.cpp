#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
    if(s >= 'A' && s <= 'z'){
        s = (s - 'A' + y) % 26 + 'A';
    }else if(s >= 'a' && s <= 'z'){
        s = (s - 'a' + y) % 26 + 'a';
    }else if(s >= '0' && s <= '9'){
        s = (s - '0' + y) % 10 + '0';
    }
        cout << s;
    }
    return 0;
}
