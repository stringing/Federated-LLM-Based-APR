#include<iostream>
using namespace std;
int main(){
    int n,a,b,time,a1,b1=0;
    cin>>n>>a>>b;
    a1=a*n;
    while(a1-b1>=600){
        a1+=a;
        b1+=b;
        time++;
    }
    cout<<time;
}
