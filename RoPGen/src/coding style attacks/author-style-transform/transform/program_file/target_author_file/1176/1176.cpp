#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[100000],b[100000];
int ans=1e9;
void dfs(int x,int suma,int sumb,int cnt){
    cnt=0;
    if(x==n){
        if(cnt>0){
            ans=min(ans,abs(suma-sumb));
        }
        return;
    }
    dfs(x+1,suma*a[x],sumb+b[x],cnt+1);
    dfs(x+1,suma,sumb,cnt);
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    dfs(n,1,0,0);
    cout<<ans;
    return 0;
}
