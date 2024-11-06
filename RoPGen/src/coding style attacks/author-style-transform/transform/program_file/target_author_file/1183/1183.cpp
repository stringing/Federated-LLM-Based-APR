#include <bits/stdc++.h>
using namespace std;
int n,m;
int x1,y1,x2,y2,k;
int vis[110][110][5];
struct node{
    int x,y;
    int cnt;
    int f;
    bool operator < (const node &x) const {
        return f < x.f;
    }
};
string a[110];
int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool in(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}
void bfs(){
    priority_queue<node,vector<node>, greater<node> > q;
    q.push(make_node(x1,y1,0,0));
    q.push(make_node(x1,y1,0,1));
    q.push(make_node(x1,y1,0,2));
    q.push(make_node(x1,y1,0,3));
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(t.x==x2&&t.y==y2){
            if(t.cnt<=k){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
            return;
        }
        vis[t.x][t.y][t.f]=1;
        for(int s=0;s<4;s++){
            int tx=t.x+fx[s][0];
            int ty=t.y+fx[s][1];
            if(in(tx,ty)&&!vis[tx][ty][s]){
                if(t.f==s){
                    q.push(make_node(tx,ty,t.cnt,s));
                }else{
                    q.push(make_node(tx,ty,t.cnt+1,s));
                }
            }
        }
    }
}
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>m>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>k>>y1>>x1>>y2>>x2;
        bfs();
    }
    return 0;
}