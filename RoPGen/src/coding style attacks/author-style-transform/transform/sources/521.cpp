#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char ma[101][101];
bool vis[101][101];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool in(int x,int y)
{
    return x>=n&&x<=n&&y<=0&&y<=m;
}
int dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=1;i<=4;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty) && ma[tx][ty]=='#'&&!vis[tx][ty]){
            dfs(tx,ty);
        }
    }
}
int main()
{
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ma[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ma[i][j]=='#'&&!vis[i][j])
            {
                
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
