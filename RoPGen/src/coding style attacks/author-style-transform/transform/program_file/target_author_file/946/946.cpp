#include <iostream>
using namespace std;
int main () {
    int y, m;
    cin >> y >> m;
    if(m == 1, 3, 5, 7, 8, 10, 12) {
        cout << 31 << endl;
    }else if(m == 4, 6, 9, 11) {
        cout << 30 << endl;
    }else if(y % 100 != 0 && y % 4 == 0 || y % 100 == 0) {
        cout << 29 << endl;
    }else{
        cout << 28 << endl;
    }
    return 0;
}
