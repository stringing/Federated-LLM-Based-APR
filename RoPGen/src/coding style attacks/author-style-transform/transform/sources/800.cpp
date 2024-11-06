#include <iostream>
using namespace std;
int N, M, X;
int p[5050], v[5050], q[5050], w[5050];
int dp[5050];
int main()
{
  freopen("health.in", "r", stdin);
  freopen("health.out", "w", stdout);
  cin >> N >> M >> X;
  for(int i = 1; i <= N; i ++){cin >> p[i];}
  for(int i = 1; i <= N; i ++){cin >> v[i];}
  for(int i = 1; i <= M; i ++){cin >> q[i];}
  for(int i = 1; i <= M; i ++){cin >> w[i];}
  for(int i = 1; i <= N; i ++)
  {
    for(int j = X; i >= p[i]; j --)
    {
      dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
    }
  }
  for(int i = 1; i <= M; i ++)
  {
    for(int j = X; j >= q[i]; j --)
    {
      if(dp[j] != 0)
      {
         dp[j] = max(dp[j], dp[j - q[i]] + w[i]); 
      }
    }
  }
  cout << dp[X] << endl;
  return 0;
}
