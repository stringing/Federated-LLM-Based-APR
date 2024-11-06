#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
     (s - 'A' + x) % 26 + 'A';
     (s - 'a' + x) % 26 + 'a';
     (s - '0' + x) % 10 + '0';
        cout << s;
    }
    return 0;
}
