#include<bits/stdc++.h>
using namespace std;
int a[25];
int n,m,ans;
void dfs(int x,int sum){
  if(x==n){
    if(sum>-m&&sum-m<ans){
      ans=sum-m;
    }return;
  }dfs(x+1,sum+a[x]);
  dfs(x+2,sum);
}
int main()
{
  freopen("shelf.in","r",stdin);
  freopen("shelf.out","w",stdout);
  cin>>n>>m;
  ans=0x3f3f3f; for(int i=0;i<n;i++)
    cin>>a[i];
dfs(0,0);
  printf("%d\n",ans);
  return 0;
}
