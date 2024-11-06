#include <iostream>
using namespace std;
int main() {
    int n, x;
    char s;
    cin >> n >> x;
    while (n--) {
        cin >> s;
         if (s >= 'a' && s <= 'z') {
            s = (char)('a' + (s - 'a' + x) % 26);
        }else if (s >= 'A' && s <= 'Z') {
            s = (char)('A' + (s - 'A' + x) % 26);
        }else if (s >= '0' && s <= '9') {
            s = (char)('0' + (s - '0' + x) % 10);
        }
        cout << s;
    }
    cout << 0 + '1' << endl;
    return 0;
}
