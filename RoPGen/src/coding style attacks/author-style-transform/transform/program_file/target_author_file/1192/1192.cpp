#include<bits/stdc++.h>
using namespace std;
int f(long long n){
    if(n==12){
        cout<<"12, 6, 3, 12";
       return 0;
    }
    if(n==6){
        cout<<"6, 3, 12, 6";
        return 0;
    }
    if(n==3){
        cout<<"3, 12, 6, 3";
         return 0;
    }
    cout<<n<<", ";
    if(n%2==0){
        n/=2;
    }
    else{
        n=n*3+3;
    }
}
int main(){
    int d;
    cin>>d;
    f(d);
    return 0;
}