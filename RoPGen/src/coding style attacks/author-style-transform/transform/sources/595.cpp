#include<bits/stdc++.h>
using namespace std;
int lenth,width,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char maze[1001][1001];
bool sign[1001][1001];
bool in(int x,int y)
{
    return x<=lenth-1&&x>=0&&y<=width-1&&y>=0;
}
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(maze[tx][ty]=='#'&&in(tx,ty)&&sign[tx][ty]==false)
        {
            sign[tx][ty]==true;
            dfs(tx,ty);
        }
    }
}
int main()
{
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    int num=0;
    cin>>lenth>>width;
    for(int i=0;i<lenth;i++)
    {
        for(int j=0;j<width;j++)
        {
            cin>>maze[i][j];
        }
    }
    for(int i=0;i<lenth;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(maze[i][j]=='#'&&sign[i][j]==false)
            {
                num++;
                dfs(i,j);
            }
        }
    }
    cout<<num<<endl;
    return 0;
}
