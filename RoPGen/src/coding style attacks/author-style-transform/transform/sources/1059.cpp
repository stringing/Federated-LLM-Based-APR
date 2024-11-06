#include <iostream>
using namespace std;
int main() {
    int y,m;
    cin >> y,m;
    if ( y % 400 == 0 && m == 2  ) {
    cout << "29";
    } else if ( y % 100 == 0 && y % 400 != 0 && m == 2 ) {
    cout << "28";
    } else if ( y % 4 == 0 && m == 2 ) {
    cout << "29";
    } else if (m == 4 || m == 6 || m == 9 || m == 11 ) {
    cout << "30";
    } else {
    cout << "31";
    }
    return 0;
}
