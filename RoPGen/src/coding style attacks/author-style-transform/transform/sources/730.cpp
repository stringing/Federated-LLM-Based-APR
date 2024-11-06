#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1201920][24],a[94],c[1021][1034],n,m,k;
signed main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<k;++i)
    {
        int x,y,C;
        cin>>x>>y>>C;
        c[x][y]=C;
    }
    
    for(int i=0;i<n;++i)
        dp[1<<i][i]=a[i];
    for(int i=0;i<(1<<n)-1;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(!(i&(1<<j)))
            {
                for(int k=0;k<n;++k)
                {
                    if(i&(1<<k))
                    {
                        dp[i|(1<<j)][j]=dp[i][k]+a[j]+c[k][j];
                    }
                }
            }
        }
    }
    int ans=-1;
    for(int i=0;i<(1<<n)-1;++i)
        for(int j=0;j<n;++j)
            ans=max(ans,dp[i][j]);
    cout<<ans;
}
