#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <cstdio>
using namespace std;
struct node{
    int x,y,d,ans;
    
};
deque<node> q;
int dir[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
char a[1000][1000];
bool vis[1000][1000];
int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        while (!q.empty()) q.pop_front();
        memset(vis, 0, sizeof(vis));
        int m,n;
        cin >>m >> n;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        int k,x1,y1,x2,y2;
        cin >> k >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        if (a[x1][y1] == '*') {
            cout << "no" << endl;
            continue;
        }
        q.push_front((node){x1, y1, 0, 0});
        q.push_front((node){x1,y1, 1, 0});
        q.push_front((node){x1, y1, 2, 0});
        q.push_front((node){x1, y1, 3, 0});
        int t1 = false;
        while (!q.empty()) {
            node u = q.front();
            vis[u.x][u.y] = true;
            if (u.x == x2 && u.y == y2) {
                cout << "yes" << endl;
                t1 = true;
                break;
            }
            q.pop_front();
            for (int i = 0; i <= 3; i++) {
                int tx = u.x + dir[i][0];
                int ty = u.y + dir[i][1];
                if (a[tx][ty] != '*' && !vis[tx][ty] && tx >= 0 && tx < m && ty >= 0 && ty < n) {
                    if(u.d == i) {
                        q.push_front((node){tx, ty, i, u.ans});
                    } else {
                        if (u.ans + 1 <= k) q.push_back((node){tx, ty, i, u.ans + 1});
                    }
                }
            }
        }
        if (!t1) {
            cout << "no" <<endl;
        } 
    }
    return 0;
}
