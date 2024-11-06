#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
int a[1000][1000],s=0,ans=0,n,m,dxy[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[1000][1000];
void bfs(int sx,int sy){
    queue<node> q;
    vis[sx][sy] = 1;
    q.push(node{sx,sy});
    while(q.size()){
        node cur=q.front();
        q.pop();
        s = s + a[sx][sy]; 
        for(int i=0; i<4; i++){
            int nx=cur.x+dxy[i][0],ny=cur.y+dxy[i][1];
            if(nx<1||nx>n||ny<1||ny>m){
                continue;
            }
            if(a[nx][ny]==1&&!vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push(node{nx,ny});
            }
        } 
    }
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]>0&&!vis[i][j]){
                s = 0;
                bfs(i,j);
                if(s>ans){
                    ans = s;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
