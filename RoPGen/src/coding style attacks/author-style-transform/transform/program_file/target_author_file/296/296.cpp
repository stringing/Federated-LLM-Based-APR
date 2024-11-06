#include<bits/stdc++.h>
using namespace std;
int n,a[15],b[15],ans=0x3f3f3f3f;
void dfs(int u,int cnt,int sum,int mul){
    if(cnt==0&&u==n-1){
        return;
     }
    if(sum>mul&&cnt!=0&&sum!=0&&mul!=1){
        ans=min(ans,(sum-mul));}
    else{
        ans=min(ans,(mul-sum));
        }
    if(u>=n){
        return;
    }
    cout<<sum<<' '<<mul<<'\n';
    dfs(u+1,cnt+1,sum+b[u],mul*a[u]);
    dfs(u+1,cnt,sum,mul);
    return;
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }
    dfs(0,0,0,1);
    cout<<ans<<'\n';
    return 0;
}

