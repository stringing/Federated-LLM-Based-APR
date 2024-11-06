#include<bits/stdc++.h>
using namespace std;
int ans=1e9,a[15],b[15],n,l,ll;
void dfs(int i,int s1,int s2){
    if(i==n){
        if(abs(s1-s2)<abs(ans))ans=s1-s2;
        return ;
    }
    dfs(i+1,s1*a[i],s2+b[i]);
    dfs(i+1,s1,s2);
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    dfs(0,1,0);
    cout<<abs(ans);
    return 0;
}
