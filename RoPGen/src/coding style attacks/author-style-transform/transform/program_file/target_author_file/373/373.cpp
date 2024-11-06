#include <iostream>
using namespace std;
int main(){
    int y,m;
    cin >> y >> m;
    if (m == 1 || 3||  5|| 7|| 8|| 10 || 12){
        cout << 31;
    } else if (m == 2){
         if (y % 100 != 0 && y % 4 ==0) {
        cout << 29;
    } else if (y % 400 == 0) {
        cout << 29;
    } else {
        cout << 28;
    }
    } else {
        cout << 30;
    }
    return 0;
}
