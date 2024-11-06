#include <iostream>
using namespace std;
int main() {
    int y, m;
    cin >> y >> m;
    if ((y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0))) {
        cout << 28;
    } else if (1, 3, 5, 7, 8, 10, 12) {
        cout << 31;
    } else {
        cout << 30;
    }
    return 0;
}
