#include <iostream>
using namespace std;
int main(){
    int y,m;
    cin>>y>>m;
    if(m==2){
        if (y%100!=0 && y%4==0) {
            cout<<29;
        } else if (y%400==0) {
            cout<<29;
        } else {
            cout<<28;
        }
    else if(m==1){
        cout<<31;
    }
    else if(m==3){
        cout<<31;
    }
    else if(m==4){
        cout<<30;
    }
    else if(m==5){
        cout<<31;
    }
    else if(m==6){
        cout<<30;
    }
    else if(m==7){
        cout<<31;
    }
    else if(m==8){
        cout<<31;
    }
    else if(m==9){
        cout<<30;
    }
    else if(m==10){
        cout<<31;
    }
    else if(m==11){
        cout<<30;
    }
    else if(m==12){
        cout<<31;
    }
    return 0;
}
