#include <cstdio>
#include <algorithm>
#define BFSNEXT now.score+map[now.x,now.y],now.from
using namespace std;

int n, m, x, y, v, c;
int map[1010][1010];
struct queue
{
  int x, y;
  int score;
  int from;
  
  void init(const int _x, const int _y, const int _score, const int _from)
  {
    x = _x, y = _y, score = _score, from = _from;
  }
};
queue q [10101];
int l = 0, r = 0;
int ans = -1;

int main ()
{
  freopen ("escape.in", "r", stdin);
  freopen ("escape.out", "w", stdout);
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &v, &c);
  for (int i = 1; i <= n; i ++)
  {
     for (int j = 1; j <= m; j ++)
     {
       scanf("%d", &map[i][j]);
     }
  }
  
  
  q[r++].init(1, 1, c, 1), q[r++].init(1, m, c, 2), q[r++].init(n, 1, c, 3), q[r++].init(n, m, c, 4);
  while (l < r)
  {
    int nx = q[l].x, ny = q[l].y, ns = q[l].score, nf = q[l].from, nm = map[nx][ny];l++;
    if (ns <= 0)
    {
      continue;
    }
    else if ( ns > c)
    {
      ns = c;
    }
    if (nx == x && ny == y)
    {
      ans = max(ans, ns);
    }
    else if (nf == 1)
    {
      if (0 < nx + 1 && nx + 1 <= n)
        q[r++].init(nx + 1, ny, ns + nm, nf);
      if (0 < ny + 1 && ny + 1 <= m)
        q[r++].init(nx, ny + 1, ns + nm, nf);
    }
    else if (nf == 2)
    {
      if (0 < nx + 1 && nx + 1 <= n)
        q[r++].init(nx + 1, ny, ns + nm, nf);
      if (0 < ny - 1 && ny - 1 <= m)
        q[r++].init(nx, ny - 1, ns + nm, nf);
    }
    else if (nf == 3)
    {
      if (0 < nx - 1 && nx - 1 <= n)
        q[r++].init(nx - 1, ny, ns + nm, nf);
      if (0 < ny + 1 && ny + 1 <= m)
        q[r++].init(nx, ny + 1, ns + nm, nf);
    }
    else
    {
      if (0 < nx - 1 && nx - 1 <= n)
        q[r++].init(nx - 1, ny, ns + nm, nf);
      if (0 < ny - 1 && ny - 1 <= n)
        q[r++].init(nx, ny - 1, ns + nm, nf);
    }
  }
  
  printf("%d\n", ans);
  return 0;
}
