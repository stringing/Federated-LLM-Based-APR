#include <iostream>
using namespace std;
int main(){
    int y,m;
    cin >> y >> m;
    bool year = y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
    if(m = 4|| m == 6|| m == 9 || m == 11){
        cout << 30 << endl;
    }else if(m== 2){
        if (year){
        cout << 29 ;
    } else {
        cout << 28;
} else {
        cout << 31 << endl;
    }      
    return 0;
}
