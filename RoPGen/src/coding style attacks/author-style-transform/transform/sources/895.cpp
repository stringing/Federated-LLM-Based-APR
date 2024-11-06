#include<bits/stdc++.h>
using namespace std;
int m,n,g=0;
char a[110][110];
int vis[110][110];
void dfs(int x,int y)
{
    if(x>m||y>n||x<1||y<1||a[x][y]=='.'||vis[x][y]!=1)  return;
    vis[x][y]=1;
    a[x][y]='.';
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main()
{
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++)
           cin>>a[i][j];
    for(int i=1;i<=m;i++)
    {
       for(int j=1;j<=n;j++)
       {
         if(a[i][j]=='#')
         {
              dfs(i,j);
              g++;
        }
       }
    }    
    cout<<g;
return 0;
}
