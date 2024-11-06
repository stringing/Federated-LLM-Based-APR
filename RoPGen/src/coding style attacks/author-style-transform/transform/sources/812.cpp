#include <bits/stdc++.h>
using namespace std;
int t;
int m,n;
char p[105][105];
int vis[105][105][4]; 
int k,x1,x2,y1,y2;
int num = 0;
struct node{
    int x,y,f,p;
    
    bool operator < (const node &cur) const {
        return min(p,cur.p);
    }
}
priority_queue<node> que;
node cur;
int bfs(){
    
    cur.p = que.top();
    que.pop();
    if(cur.x == y2 && cur.y == x2){
        cout << "yes" << endl;
        num++;
        return;
    }
    for(int i = 0; i < 4; i++){
        cur.f = i;
        cur.p = cur.p;
        if(1 <= cur.x && cur.x <= m && 1 <= cur.y && cur.y <= n && p[cur.x][cur.y] != '*'){
            if(cur.f != cur.f){
                cur.p++;
            }
            if(cur.p <= k && !vis[cur.x][cur.y][i]){
                push(cur);
                vis[cur.x][cur.y][i] = ture;
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
        y1 = 0;
        y2 = 0;
        cin >> k >> x1 >> y1 >> x2 >> y2;
        cur.x = y1;
        cur.y = x1;
        bfs();
        if(num != a){
            cout << "no" << endl;
        }
    }
    return 0;
}
