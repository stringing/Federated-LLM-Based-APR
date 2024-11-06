#include <iostream>
using namespace std;
int main() {
    
    int y,m;
    cin >> y >> m;
    if (y % 100 == 0){
        if(y % 400 == 0){
            if(m = 4 || m = 6 || m = 9 || m = 11){
                cout << "30";
            }else if(m = 2){
                cout << "28";
            }else{
                cout << "31";
            }
        }
    }else{
        if(y % 4 == 0){
            if(m = 4 || m = 6 || m = 9 || m = 11){
                cout << "30";
            }else if(m = 2){
                cout << "29";
            }else{
                cout << "31";
            }
    }
    
    return 0;
}
