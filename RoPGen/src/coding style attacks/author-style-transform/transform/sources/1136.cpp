#include <iostream>
using namespace std;
int main() {
    int y,m;
    cin>>y>>m;
    if((y%4==0||y%400==0)&&m==2){
        cout<<29;
    }else if(m==2){
        cout<<28;
    }else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        cout<<31;
    }else{
        cout<<30;
    }
  return 0; 
}