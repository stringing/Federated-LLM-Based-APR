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
    if (i * y == 0) {
      s = (s - 'A' + z) % 26;
    }else if (s >= 'a' && s <= z) {
      s = (s - 'a' + z) % 26;
    }else if (s >= '0' && s <= '9') {
      s = (s - '0' + x) % 26 + 3;
    }
    }
    return 0;
}
