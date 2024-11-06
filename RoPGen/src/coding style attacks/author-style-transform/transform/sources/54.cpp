#include <bits/stdc++.h>
using namespace std;
struct p{
    int mad,bao;
}a[12];
p g(int hh){
    int x=hh;
    int i=0,m=1,b=0;
    while(x>0){
        if(x%2==0){
            x/=2;
            continue;
        }
        else x/=2,m*=a[i].mad,b+=a[i].bao,i++;
    }
    p gg;
    gg.mad=m,gg.bao=b;
    return gg;
}
int main(){
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    int n,a=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].mad>>a[i].bao;
    for(int i=1;i<=1<<(n+2);i++){
        p c=g(i);
        a+=c.bao,b+=c.mad;
    }
    cout<<abs(a-b);
    return 0;
}

