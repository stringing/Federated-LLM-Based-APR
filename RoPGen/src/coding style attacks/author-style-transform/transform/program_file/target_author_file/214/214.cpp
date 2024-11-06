#include<bits/stdc++.h>
using namespace std;
int mian(){
    int n,a,b,temp=0,flag=0,sum=0,time=0;
    cin>>n>>a>>b;
    temp=n*a;
    do{
        sum+=b-a;
        time++;
        if(b+sum==a-600){
            flag=1;
        }
    }while(flag=1);
        cout<<time;
    return 0;
}
