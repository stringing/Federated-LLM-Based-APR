#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2][5010];
int w[5010],c[5010];
int main() 
{
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int N,M,V;
    cin>>N>>M>>V;
    for(int i=1;i<=N;i++) 
    {
        cin>>c[i]>>w[i];
    }
    for(int i=N+1;i<=M+N;i++)
    {
        cin>>c[i]>>w[i];
    }
    N=M+N;
    int flag=1;
    for (int i=1;i<=N;i++) 
    {
        for(int j=0;j<=V;j++)
        {
            if(j>=c[i])
            {
                dp[flag][j]=max(dp[1-flag][j-c[i]]+w[i],dp[1-flag][j]);
            }
            else
            {
                dp[flag][j]=dp[1-flag][j];
            }
        }
        flag=1-flag;
    }
    cout<<dp[1-flag][V]<<endl;
    return 0;
}
