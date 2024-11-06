#include <iostream>
using namespace std;
int main(){
    int y, x;
    cin >> x >> y;
    if (x == 2 && y % 4 == 0 && y % 100 != 0 || x == 2 && y % 100 == 0 && y % 400 == 0){
        cout << "29" << endl;
    }else if (x == 2 && y % 100 == 0 && y % 400 != 0){
        cout << "28" << endl;
    }else if (x == 4 || x == 6 || x == 9 || x == 11){
        cout << "30" << endl;
    }else{
        cout << "31" << endl;
    }
    return 0;
}
