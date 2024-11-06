#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;

int a[110][110][110], dp[110][110][110];

int main() {
  freopen("escape.in","r",stdin); freopen("escape.out","w",stdout);
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                cin >> a[i][j][k];
            }
        }
    }
    for(int i=0;i<=x;i++)
    {
      for(int j=0;j<=y;j++){
        for(int k=0;k<=z;k++){
          if(i==0&&j==0&&k==0)
          {
            dp[i][j][k]=a[i][j][k];
          }else {
            dp[i][j][k]=inf;
          }if(i!=0)
          {
            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+a[i][j][k]);
          }
          if(j!=0)
          {
            dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k]+a[i][j][k]);
          }
          if(k!=0){
            dp[i][j][k]=min(dp[i][j][k],dp[i][j][k-1]+a[i][j][k]);
          }
        }
      }
    }cout<<dp[x][y][z]<<endl;
    return 0;
}
