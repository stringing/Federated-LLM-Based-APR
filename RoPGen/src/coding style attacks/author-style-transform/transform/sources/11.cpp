#include <iostream>
using namespace std;
int main (){
    int y, m;
    cin >> y, m;
    if (m == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
        cout << "31";
    } else if (m == 4 || 6 || 9 || 11) {
        cout << "30";
    } else if (m == 2 && (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0))) {
        cout << "29";
    } else if (m == 2 && (y % 400 != 0) || ((y % 100 != 0) && (y % 4 != 0))) {
        cout << "28";
    }
    return 0;
}

