#include<bits/stdc++.h>
using namespace std;
int ans=1e9,a[15],n,l,ll;
void dfs(int i,int s){
    cout<<s<<endl;
    if(i==n){
        if(abs(s)<abs(ans))ans=s;
        return ;
    }
    dfs(i+1,s+a[i]);
    dfs(i+1,s);
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l>>ll;
        a[i]=ll-l;
    }
    dfs(0,0);
    cout<<abs(ans);
    return 0;
}
