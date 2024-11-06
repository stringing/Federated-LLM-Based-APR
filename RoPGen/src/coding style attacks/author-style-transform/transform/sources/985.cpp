#include <iostream>
using namespace std;
int main (){
    int y, m;
    cin >> y >> m;
      if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        if ( m == 2){
            cout << 29 << endl;
        }else{
         cout << 28 << endl; 
        }
    }       
     if ( m == 1){
        cout << 31 << endl;
    } else if ( m == 3){
        cout << 31 << endl;
    } else if ( m == 4){
        cout << 30 << endl;
    } else if ( m == 5){
        cout << 31 << endl;
    } else if ( m == 6){
        cout << 30 << endl;
    } else if ( m == 7){
        cout << 31 << endl;
    } else if ( m == 8){
        cout << 31 << endl;
    } else if ( m == 9){
        cout << 30 << endl;
    } else if ( m == 10){
        cout << 31 << endl;
    } else if ( m == 11){
        cout << 30 << endl;
    } else if ( m == 12){
        cout << 31 << endl;
    }
    return 0;
 } 
