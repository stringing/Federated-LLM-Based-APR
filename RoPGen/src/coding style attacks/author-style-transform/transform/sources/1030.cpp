#include<bits/stdc++.h>
using namespace std;
struct q{
    int x;
    int y;
};
int n,ans=pow(10,9)*2,sum1=1,sum2=0;
q a[15];
void dfs(int x){
    sum1*=a[x].x;
    sum2+=a[x].y;
    if(x!=0){
        ans=min(abs(sum1-sum2),ans);
    }
    for(int i=x+1;i<=n;i++){
        dfs(i);
    }
    sum1/=a[x].x;
    sum2-=a[x].y;
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    a[0].x=1;
    dfs(0);
    cout<<ans;
    return 0;
}
