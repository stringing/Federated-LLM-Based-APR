#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,m1,m2 = 0,time,time2 = 0;
    cin>>n>>a>>b;
    m1 = a * n;
    time = n / (a-b);
    for(int i = 0; i < time; i++){
        if(m1-m2 <= 600){
            cout<<time2;
            return 0;
        }
        else{
            m1 += a;
            m2 += b;
        }
        time2 ++;
    }
}
