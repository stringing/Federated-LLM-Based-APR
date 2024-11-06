#include <iostream>
using namespace std;
int main() {
 int y,m;
    cin >> y >> m;
    if(y % 4 || 400 == 0) && ( m = 2){
    cout << "29";
    } if(y % 4 || 400 != 0) &&  (m = 2){
        cout << "28";
    } if(y % 4 && y % 400 != 0) && (m = 1||3||5||7||8||10||12){
        cout << "31";
    } if(y % 4 && y % 400 != 0) && (m = 4||6||9||11){ 
       cout << "30";
    }
        return 0;
}    
