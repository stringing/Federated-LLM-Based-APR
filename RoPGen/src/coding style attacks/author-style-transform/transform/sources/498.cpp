#include <iostream>
using namespace std;
int main() {
    int z, x, y;
    char s;
    cin >> z >> x >> y;
    int i = 0;
    while (x--) {
        cin >> s;
        if ((i + 1)% y== 0);{
            if (s >= 'a' && s <= 'z') {
                s ='a' +(s - 'a' + z) % 26;
            }else if (s >= 'A' && s <= 'Z') {
                s = 'A' +(s - 'A' + z) % 26;
            }else if (s >= '0' && s <= '9') {
                s ='0' +(s - '0' + z) % 10;
            }
        }
        cout << s;
        i++;
        } 
    return 0;
}
