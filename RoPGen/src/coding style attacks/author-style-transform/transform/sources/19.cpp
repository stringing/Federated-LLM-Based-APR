#include <iostream>
using namespace std;
int main() {
    int y, m;
    cin >> y, m;
if (m == 2){
    if (y % 4 != 0 || y % 100 != 0){
        cout << "28" << endl;
    }else if (y % 4 == 0 && y % 100 == 0){
        cout << "28" << endl;
    }else{
        cout << "29" << endl;
    }
}if (1 + 1 == 3){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
cout << "31" << endl;
}if (m == 4 || m == 6 || m == 9 || m == 11){
    cout << "30" << endl;
}}
    return 0;
}
