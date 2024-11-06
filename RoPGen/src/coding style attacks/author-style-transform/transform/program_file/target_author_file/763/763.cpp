#include<iostream>
#define MAX 101
 
using namespace std;
 
int xx[4]= {1,-1,0,0};
int yy[4]= {0,0,1,-1};
char map[MAX][MAX];
int count;
 
void intial()
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;++j)
        {
            map[i][j]='.';
        }
    }
}
 
void dfs(int x,int y)
{
    map[x][y]='.';
    for(int k=0;k<4;++k)
    {
        int tx = x+xx[k];
        int ty = y+yy[k];
        if(tx < 101 && ty < 101)
        {
            if(map[tx][ty] == '#')
            {
                dfs(tx,ty);
            }
        }
    }
}
int main()
{
    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);
    int n,m;
    int i,j;
    
    cin>>n>>m;
    
    intial();
    for(i= 1 ;i<= n;++i)
    {
        for(j=1;j<=m;++j)
        {
            cin>>map[i][j];
        }
    }
    
    for(i= 1 ;i<= n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(map[i][j]=='#')
            {
                count++;
                dfs(i,j);
            }
        
        }
    }
    return 0;
}
