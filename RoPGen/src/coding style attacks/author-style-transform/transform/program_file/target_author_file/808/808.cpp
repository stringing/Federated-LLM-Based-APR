#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5010];
int w[5010],c[5010];
int main() 
{
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int N,M,V;
    cin>>N>>M>>V;
    for(int i=1;i<=N;i++) 
    {
        cin>>c[i];
    }
    for(int i=1;i<=N;i++)
    {
        cin>>w[i];
    }
    for(int i=N+1;i<=M+N;i++)
    {
        cin>>c[i];
    }
    for(int i=N+1;i<=M+N;i++)
    {
        cin>>w[i];
    }
    int flag=1;
    for(int i=1;i<=N;i++) 
    {
        for(int j=V;j>=c[i];j--)
        {
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    for(int i=N;i<=N+M;i++) 
    {
        for(int j=V;j>=c[i];j--)
        {
            if(dp[j]!=0)
            {
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);            
            }
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
