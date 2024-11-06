#include<iostream>
using namespace std;
int main(){
    int y,m;
    cin >> y >> m;
    if(m == 1){
        cout << 31;
    }else if(m == 3){
        cout << 31;
    }else if(m == 5){
        cout << 31;
    }else if(m == 7){
        cout << 31;
    }else if(m == 8){
        cout << 31;
    }else if(m == 10){
        cout << 31;
    }else if(m == 12){
        cout << 31;
    }else if(m != 2){
        cout << 30;
    }
    if(m == 2 && y / 400 == 1){
        cout << 29;
    }else if(m == 2 && y % 400 != 0){
        cout << 28;
    }else if(y % 4 == 0 && y % 44 == 0){
        cout << 28;
    }
    return 0;
}
