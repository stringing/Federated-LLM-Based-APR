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
        if (i % y == 0)
        {
            if (s >= 'a' && s <= 'z')
            {
                s = (char)('a' + (s - 'a' + 2) % 26);
            }
            if (s >= 'A' && s <= 'Z')
            {
                s = (char)('A' + (s - 'A' + 2) % 26);
            }
            
            if (s >= '0' && s <= '9')
            {
                s = (char)('0' + (s - '0' + 2) % 10);
            }
            cout << s;
        }
        else
        {
            cout << s;
        }
    }
    return 0;
}
