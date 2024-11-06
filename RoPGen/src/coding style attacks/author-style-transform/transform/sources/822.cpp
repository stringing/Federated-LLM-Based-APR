#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long long n;
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    cin>>n;
    if(n<1000000000000000000){
        cout<<n+2018<<endl;
    }else{
        long long a=9223372036854777825;
        cout<<a;
    }
    return 0;
}
