#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int t;
char s[1001][1001];
struct node{
    int x,y,q,f;
};
deque<node> deq;
int vis[101][101][10];
int x1,x2,y11,y2,k;
int df1[5]={0,1,0,1,0},df2[5]={0,0,1,0,1};
bool hf(int x,int y,int i)
{
    return x+df1[i]>0&&x+df1[i]<=n&&y+df2[i]>0&&y+df2[i]<=m;
}
bool bfs()
{
    while(!deq.empty())
    {
        node now=deq.front();
        deq.pop_front();
        if(now.q>k)
        {
            continue;
        }
        if(now.x==x2&&now.y==y2)
        {
            return true;
        }
        for(int i=1;i<=4;i++)
        {
            int x=now.x,y=now.y,q=now.q,f=now.f;
            vis[x][y][f]=1;
            if(i==f&&vis[x+df1[i]][y+df2[i]][i]==0&&hf(x,y,i))
            {
                deq.push_front(node{x+df1[i],y+df2[i],q,f});
            }else{
                deq.push_front(node{x+df1[i],y+df2[i],q+1,i});
            }
        }
    }
    return false;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof(s));
        memset(vis,0,sizeof(vis));
        deq.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='*')
                {
                    vis[i][j][1]==1;
                    vis[i][j][2]==1;
                    vis[i][j][3]==1;
                    vis[i][j][4]==1;
                }
            }
        }
        cin>>k>>x1>>x2>>y11>>y2;
        deq.push_front(node{x1,y11,1});
        deq.push_front(node{x1,y11,2});
        deq.push_front(node{x1,y11,3});
        deq.push_front(node{x1,y11,4});
        if(bfs())
        {
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
