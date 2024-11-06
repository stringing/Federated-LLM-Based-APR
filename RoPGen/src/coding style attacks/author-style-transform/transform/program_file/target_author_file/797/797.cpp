#include <bits/stdc++.h>
using namespace std;
struct p{
    int mad,bao;
}a[12];
int g(int hh){
    int x=hh;
    int i=0,m=1,b=0;
    while(x>0){
        if(x%2==0){
            x/=2,i++;
            continue;
        }
        else x/=2,m*=a[i].mad,b+=a[i].bao,i++;
    }
    return abs(m-b);
}
int main(){
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    int n,ans=0x3f3f3f3f;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].mad>>a[i].bao;
    for(int i=1;i<=1<<(n+2);i++){
        ans=min(ans,g(i));
    }
    cout<<ans;
    return 0;
}

