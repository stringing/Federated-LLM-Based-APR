#include <iostream>
using namespace std;
int main() {
    int y, m;
    cin >> y >> m;
    if (m == 1, 3, 5, 7, 8, 10, 12){
        cout << "31" << endl;
    } else if (y % 400 == 0){
        cout << "28" << endl;
    } else if (y % 100 != 0 && y % 4==0){
        cout << "29" << endl;
    } else {
         cout << "30" << endl;
    }
    return 0;
}
