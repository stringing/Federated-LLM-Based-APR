#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a%4==0){
        if(b==1||b==3||b==5||b==7||b==8||b==10||b==12){
            cout<<31;
        }
        else if(b==4||b==6||b==9||b==11){
            cout<<30;
        }
        else cout<<29;
        }
    else{
        if(b==1||b==3||b==5||b==7||b==8||b==10||b==12){
            cout<<31;
        }
        else if(b==4||b==6||b==9||b==11){
            cout<<30;
        }
        else cout<<28;
    }
    return 0;
}
