#include<bits/stdc++.h>
using namespace std;
struct strone{
    int fn;
    int bz;
}s[20];
int n,ans = INT_MAX;
bool vis[20];
void dfs(int sum1,int sum2,int k){
    if(k == n+1){
        if(abs(sum1 - sum2) < ans){
            ans = abs(sum1 - sum2);
        }
        return;
    }
    if(vis[k] == false){
        vis[k] = true;
        dfs(sum1 * s[k].fn,sum2 + s[k].bz,k+1);
        vis[k] = false;
        dfs(sum1,sum2,k+1);
    }
    
}
int main(){
    freopen("strone.in","r",stdin);
    freopen("stone.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&(s[i].fn),&(s[i].bz));
    }
    vis[1] = true;
    dfs(1,0,1);
    printf("%d",ans);
    return 0;
}
