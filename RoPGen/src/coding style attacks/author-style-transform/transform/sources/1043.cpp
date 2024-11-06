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
  
  void init(int _x, int _y, int _score, int _from)
  {
    x = _x;
    y = _y;
    score = _score;
    from = _from;
  }
}q[101010];
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
  
  
  q[r++].init(x, y, c, 1), q[r++].init(x, y, c, 2), q[r++].init(x, y, c, 3), q[r++].init(x, y, c, 4);
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
    if ((nx == 1 && ny == 1) || (nx == n && ny == 1) || (nx == 1 && ny == m) || (nx == n && ny == m))
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
