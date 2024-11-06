#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int d[MAXN][MAXN][4];
bool vis[MAXN][MAXN][4];
int n, m;
string maze[MAXN];
int dis(int *x) {
    return min(min(x[0], x[1]), min(x[2], x[3]));
}
void init() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            d[i][j][0] = INF;
            d[i][j][1] = INF;
            d[i][j][2] = INF;
            d[i][j][3] = INF;
            vis[i][j][0] = 0;
            vis[i][j][1] = 0;
            vis[i][j][2] = 0;
            vis[i][j][3] = 0;
        }
    }
    for (int i = 0; i < MAXN; i++) {
        maze[i] = "";
    }
}
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int k, x1, x2, y1, y2;
struct Node {
    int x;
    int y;
    int step;
    int last;
};
void bfs(int x, int y) {
    deque<Node> deq;
    d[x][y][0] = 0;
    d[x][y][1] = 0;
    d[x][y][2] = 0;
    d[x][y][3] = 0;
    deq.push_back({x, y, 0, 0});
    deq.push_back({x, y, 0, 1});
    deq.push_back({x, y, 0, 2});
    deq.push_back({x, y, 0, 3});
    while (!deq.empty()) {
        Node now = deq.front();
        int nx = now.x;
        int ny = now.y;
        int lc = now.last;
        int ns = now.step;
        deq.pop_front();
        if (vis[nx][ny][lc]) continue;
        if (maze[nx][ny] == '*') continue;
        vis[nx][ny][lc] = 1;
        for (int i = 0; i < 4; i++) {
            int tx = nx + dir[i][0];
            int ty = ny + dir[i][1];
            if (!(tx >= 0 && tx < n && ty >= 0 && ty < m)) continue;
            if (i == lc) {
                if (!vis[tx][ty][i]) { 
                    deq.push_front({tx, ty, ns, lc});
                    d[tx][ty][lc] = ns;
                }
            } else {
                if (!vis[tx][ty][i]) {
                    deq.push_back({tx, ty, ns + 1, i});
                    d[tx][ty][lc] = ns + 1;
                }
            }
        }
    }
}
void go() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    
    cin >> k >> x1 >> y1 >> x2 >> y2;
    x1--; y1--;
    x2--; y2--;
    swap(x1, y1);
    swap(x2, y2);
    bfs(x1, y1);
    if (dis(d[x2][y2]) > k + 1) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
    return;
}
int main() {
    freopen ("maze.in", "r", stdin);
    freopen ("maze.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        go();
    }
    return 0;
}
