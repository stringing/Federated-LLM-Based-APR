#include<bits/stdc++.h>
#include<queue>
#include<string>
using namespace std;
const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int n,m,t;
char c[105][105];
bool vis[105][105][6];
struct node{
    int t,x,y,k;
    bool operator<(const node &a)const{
        return t>a.t;
    }
}tmp,temp;
node mnode(int t,int x,int y,int k){
    temp.t = t;
    temp.x = x;
    temp.y = y;
    temp.k = k;
    return temp;
}
priority_queue<node> q;
int main(){
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin>>t;
    int k,x1,x2,y1,y2;
    while(t--){
        cin >> n >> m;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i ++){
            scanf("%s",c[i]+1);
        }
        scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
        q.push(mnode(0,x1,y1,0));
        int ans = 0;
        while(q.size()){
            tmp = q.top();
            q.pop();
            if(vis[tmp.x][tmp.y][tmp.k])continue;
            vis[tmp.x][tmp.y][tmp.k] = 1;
            if(tmp.x == x2&&tmp.y == y2){
                ans = min(ans,tmp.t);
            }
            for(int i = 0;i < 4;i ++){
                int x = tmp.x + dir[i][0];
                int y = tmp.y + dir[i][1];
                if(x > n ||x < 1 || y > m || y < 1)continue;
                if(vis[x][y][i+1])continue;
                if(c[x][y] == '*')continue;
                if(tmp.k%(i+1) == 0){
                    q.push(mnode(tmp.t,x,y,i+1));
                }else{
                    q.push(mnode(tmp.t + 1,x,y,i+1));
                }
            }
        }
        if(ans <= k){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}
