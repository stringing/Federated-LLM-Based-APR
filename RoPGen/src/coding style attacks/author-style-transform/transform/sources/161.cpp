#include<bits/stdc++.h>
using namespace std;
struct st{
    int f,b;
}a[12];
int n,minn=10000000;
void dfs(int dep,int fen,int bao){
    if(dep!=1||bao!=0)
    minn=min(minn,abs(fen-bao));
    if(dep>n)
        return;
    dfs(dep+1,fen*a[dep].f,bao+a[dep].b);
    dfs(dep+1,fen,bao);
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].f>>a[i].b;
    }
    dfs(1,1,0);
    cout<<minn<<endl;
    return 0;
}
