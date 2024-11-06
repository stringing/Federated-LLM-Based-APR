#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string n;
int a[5],b[5]={2,0,1,8,0},len=0,tmp=4;
int main(){
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    cin>>n;
    
    len=n.size();
    len=max(len,tmp);
    for(int i=1;i<=5;i++){
        a[i]=n[len-4+i];
        a[i]+=b[i];
        if(a[i]>9){
            a[i+1]+=a[i]%10;
        }
        n[len-4+i]=a[i];
    }
    cout<<n;
}
