#include <bits/stdc++.h>
using namespace std;
int t;
int m,n;
char p[105][105];
int vis[105][105][4]; 
int k,x1,x2,yo,yt;
int num = 0;
struct node{
    int x,y,f,p;
    
    bool operator < (const node &que) const {
        return p > que.p;
    }
};
priority_queue<node> que;
node cur;
node q;
void bfs(){
    
    if(!que.empty()){
        cur.p = que.top().p;
        que.pop();
    } else {
        return;
    }
    if(cur.x == x2 && cur.y == yt){
        cout << "yes" << endl;
        num++;
    }
    for(int i = 0; i < 4; i++){
        q.x = que.top().x;
        q.y = que.top().y;
        q.f = i;
        q.p = cur.p;
        if(1 <= q.x && q.x <= m && 1 <= q.y && q.y <= n && p[q.x][q.y] != '*'){
            if(num = 0 && que.top().f != cur.f){
                cur.f = que.top().f;
            }
            if(que.top().f != cur.f){
                cur.p++;
            }
            if(cur.p <= k && !vis[cur.x][cur.y][i]){
                que.push(cur);
                vis[cur.x][cur.y][i] = true;
            }
        }
    }
    bfs();
}
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin >> t;
    for(int a = 1; a <= t; a++){
        memset(p,0,sizeof(p));
        m = 0;
        n = 0;
        cin >> m >> n;
        for(int b = 1; b <= m; b++){
            for(int c = 1; c <= n; c++){
                cin >> p[b][c];
            }
        }
        k = 0;
        x1 = 0;
        x2 = 0;
        yo = 0;
        yt = 0;
        cin >> k >> x1 >> yo >> x2 >> yt;
        while(!que.empty()){
            que.pop();
        }
        cur.x = x1;
        cur.y = yo;
        cur.p = 0;
        cur.f = 0;
        que.push(cur);
        bfs();
        if(num < a){
            cout << "no" << endl;
            num++;
        }
    }
    return 0;
}
