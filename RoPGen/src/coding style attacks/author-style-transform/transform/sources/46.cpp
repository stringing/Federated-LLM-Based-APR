#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if((i + 1) % y == 0){
            if(s >= 'a' && s <= 'z'){
            s = (char)((s - 'a' + z) % 26 + 'a');
            }else if(s >= 'A' && s <= 'Z'){
            s = (char)((s - 'A' + z) % 26 + 'A');
            }else if(s >= '0' && s <= '9'){
            s = (char)((s - '0' + z) % 10 + '0');
            }
        }
        cout << s;
        } 
    return 0;
}