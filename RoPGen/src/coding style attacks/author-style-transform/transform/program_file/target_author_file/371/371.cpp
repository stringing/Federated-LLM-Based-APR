#include<cstdio>
#include<cmath>
int ANGRY[120],GRUMPY[120],n,ans=2147483647;
void dfs(int cur,int angry,int grumpy){
    if(cur==n){
        if(!grumpy) return;
        int rslt=abs(angry-grumpy);
        if(rslt<ans) rslt=ans;
    }
    dfs(cur+1,angry*ANGRY[cur],grumpy+GRUMPY[cur]);
    dfs(cur,angry,grumpy);
}
void solve()
{
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&ANGRY[i],GRUMPY[i]);
    }
    dfs(0,1,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout); 
}
int main(){
    solve();
    return 0;
}
