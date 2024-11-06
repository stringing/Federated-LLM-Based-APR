#include <iostream>
using namespace std;
int main() {
    int y, m;
    cin >> y, m;
    if (m / 2 == 1) {
        cout << "31" << endl;
    } else if (m == 2) {
        if (y / 400 == 0 || y / 100 != 0 && y / 4 == 0) {
            cout << "29" << endl;
        } else {
            cout << "28" << endl;
        }
    }else {
        cout << "30" << endl;
    }
    return 0;
}
