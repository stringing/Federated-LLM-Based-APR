#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    string s;
    int a[1000000],b[4],c[1000005];
    cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++){
        a[len-i] = s[i] - '0';  
    }
    int lenc = 1,x = 0;
    while(lenc<=len){
        c[lenc] = a[lenc]+b[lenc]+x;
        x = c[lenc]/10;
        c[lenc]%=10;
        lenc++;
    }
    for(int i=lenc;i>=1;i--){
        cout<<c[i];
    }
    return 0;
}
