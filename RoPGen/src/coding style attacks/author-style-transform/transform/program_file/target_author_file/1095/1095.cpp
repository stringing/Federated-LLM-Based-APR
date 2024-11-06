#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (i <= 100){
        cout << i << " ";
        i = i += 2
    }
    while (x--) {
        cin >> s;
        if(s >= 'A' && s <= 'Z'){
            s = (s - 'A' + 3) % 26 + 'A';
        }else if(s >= 'a' && s <= 'z'){
            s = (s - 'a' + 3) % 26 + 'a';
        }else if(s >= '0' && s <= '9'){
            s = ( s - '0' + 3) % 10 + '0';
        }
        cout << s;
    }
    return 0;
}
