#include <iostream>
using namespace std;
int main(){
    int y,m;
    cin >> y >> m;
    if (m == 2){
        if (m % 100 == 0){
            if (m % 400 == 0){
                cout << 29;
            }
        }else if (m % 4 == 0){
            cout << 29;
        }else{
            cout << 28;
        }
    }else if (m == 4 || m == 6 || m == 9 || m == 11){
        cout << 30;
    }else{
        cout << 31;
    }
    return 0; 
}
