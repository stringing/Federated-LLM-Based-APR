#include <iostream>
using namespace std;
int main (){
    int y,m;
    cin >> y>>m;
    if (y%4==0&&m==2){
        cout <<"29" <<endl;
    }
    else if (y%400!=0&&m==2&&y%100==0){
        cout <<"28"<<endl;
    }
    else if (y%400!=0&&m%2==0&&m!=2&&m!=8&&m!=10&&m!=12){
        cout <<"30"<<endl;
    }
    else  {
        cout <<"31"<<endl;
    }
    return 0;
}
