#include <iostream>
using namespace std;
int main() {
 int y,m;
    cin >> y >> m;
    if(y % 4 || 400 == 0) ( m = 2);{
    cout << "29";
    } if(y % 4 || 400 != 0) (m = 2);{
        cout << "28";
    } if (m = 1|| m =3|| m = 5|| m = 7|| m = 8|| m = 10 || m = 12){
        cout << "31";
    } if(m = 4|| m = 6|| m = 9 || m = 11){ 
       cout << "30";
    }
        return 0;
}    
