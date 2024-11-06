#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x) {
        cin >> s;
        i++;
        if (i % y == 0){
            if ('A' <= s && s <= 'Z'){
                s = (s - 'A' + z) % 26 + 'A';
            }else if('a' <= s && s <= 'z'){
                s = (s - 'a' + z) % 26 + 'a';
            }
        }
        cout << s;
        x--;
    }
    return 0;
}
