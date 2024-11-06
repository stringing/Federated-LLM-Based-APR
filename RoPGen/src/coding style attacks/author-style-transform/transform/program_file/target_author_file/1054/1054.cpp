#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=10000000,ang[15],pet[15];
void dfs(int x,int a,int p){
    if(x==n){
        ans=min(ans,abs(a-p));
        cout<<ans<<' '<<x<<' '<<a<<' '<<p<<endl;
        return;
    }
    dfs(x+1,a*ang[x],p+pet[x]);
    dfs(x+1,a,p);
}
int main(){
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d",&ang[i],&pet[i]);
    }
    dfs(0,1,0);
    printf("%d\n",ans);
    return 0;
}
