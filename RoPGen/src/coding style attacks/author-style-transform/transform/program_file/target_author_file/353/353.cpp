#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if (s >= 'A' && s <= 'Z' && s % y == 0){
            s = 'A'+(s - 'A' + x) % 26;
        }else if (s >= 'a' && s <= 'z' && s % y == 0){
            s = 'a'+(s - 'a' + x) % 26;
        }else if (s >= '0' && s <= '9' && s % y == 0){
            s = '0'+(s - '0' + x) % 10;
        }
        cout << s << endl;
    }
    return 0;
}
