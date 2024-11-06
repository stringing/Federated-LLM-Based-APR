#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[22];
int minn=10000000;
void dfs(int s,int g,int sum){
    if(sum>=g){
        minn=min(minn,sum);
        return;
}
    if(s>n)
        return;
    dfs(s+1,g,sum+=a[s]);
    dfs(s+1,g,sum);
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,m,0);
    cout<<minn-m<<endl;
    return 0;
}
