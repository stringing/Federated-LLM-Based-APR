#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        i++;
        if (s >= 'A' && s <= 'Z' && s % y == 0){
            i = 'A'+(s - 'A' + z) % 26;
        }else if (s >= 'a' && s <= 'z' && s % y == 0){
            i = 'a'+(s - 'a' + z) % 26;
        }else if (s >= '0' && s <= '9' && s % y == 0){
            i = '0'+(s - '0' + z) % 10;
        }
        cout << s << endl;
    }
    return 0;
}
