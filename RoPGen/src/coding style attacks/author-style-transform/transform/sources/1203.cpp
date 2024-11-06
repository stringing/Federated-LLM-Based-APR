#include<bits/stdc++.h>
using namespace std;
int t;
string maze[110];
int m,n,k,x1,y1,x2,y2;
bool vis[110][110];
bool in(int x,int y)
{
    return 0<=x&&x<m&&0<=y&&y<n;
}
struct node
{
    int x,y,r,rot;
    node(int xx,int yy,int rr,int rott)
    {
        x=xx;
        y=yy;
        r=rr;
        rot=rott;
    }
};
bool bfs(int sx,int sy)
{
    queue<node>q;
    q.push(node(sx,sy,0,-1));
    vis[sx][sy]=true;
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=now.x,ty=now.y;
            if(i==0)
            {
                tx++;
                if(now.rot!=0)
                    now.r++;
            }
            if(i==1)
            {
                tx--;
                if(now.rot!=1)
                    now.r++;
            }
            if(i==2)
            {
                ty++;
                if(now.rot!=2)
                    now.r++;
            }
            if(i==3)
            {
                ty--;
                if(now.rot!=3)
                    now.r++;
            }
            if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty])
            {
                if(tx==x2&&ty==y2&&now.r<=k)
                {
                    return true;
                }
                else
                {
                    vis[tx][ty]=true;
                    q.push(node(tx,ty,now.r,i));
                }
            }
        }
    }
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>m>>n;
        for(int j=0;j<m;j++)
        {
            cin>>maze[j];
        }
        cin>>k>>x1>>y1>>x2>>y2;
        if(bfs(x1,x2))  cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
