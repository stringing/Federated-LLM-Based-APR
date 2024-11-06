#include <iostream>
using namespace std;
int main() {
    int a, s, d, g = 1;
    cin >> a >> s >> d;
    char f;
    while (a--) {
        cin >> f;
        if (g % s == 0) {
            if (f >= 'a' && f <= 'z') {
                f = (f - 'a' + d) % 26 + 'a';
            } else if (f >= 'A' && f <= 'Z') {
                f = (f - "A" + d) % 26 + 'A';
            } else if (f >= '0' && f <= '9') {
                f = (f - '0' + d) % 10 + '0';
            }
        }
        cout << f;
        g++;
    }
    return 0; 
}
