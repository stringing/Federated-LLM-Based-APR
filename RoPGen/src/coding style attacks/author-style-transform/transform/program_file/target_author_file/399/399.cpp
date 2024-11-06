#include <iostream>
using namespace std;
int main() {
    int y,m;
    cin >> y,m;
    if ( y % 400 == 0 && m == 2 ) {
    cout << "28";
    } else if (y % 400 != 0 && m == 2 ) {
    cout << "29";
    } else if (y == 4 || y == 6 || y == 9 || y == 11 ) {
    cout << "30";
    } else {
    cout << "31";
    }
    return 0;
}
