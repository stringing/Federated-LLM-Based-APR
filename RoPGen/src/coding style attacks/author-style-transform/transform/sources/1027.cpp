#include<iostream>
using namespace std;
int main(){
    int y,m;
    cin >> y >> m;
    if(m != 2 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {         cout << 31 << endl;
    }else{
        cout << 30 << endl;
         }
    if(m == 2 && y / 400 == 1){
        cout << 29 << endl;
    }else if(m == 2 && y % 400 != 0){
        cout << 28 << endl;
    }
    return 0;
}
