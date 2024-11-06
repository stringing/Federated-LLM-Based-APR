#include<bits/stdc++.h>
using namespace std;
int a[20],x,y,C,c[25][25];
long long dp[1<<18][20],ans;
int main()
{
    int n,m,k,cnt,now;
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d",&x,&y,&C);
        x--;y--;c[x][y]=C;
    }
    for(int i=0;i<n;i++)
    {
        c[1<<i][i]=a[i];
    }
    for(int i=1;i<(1<<n)-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(1&(i>>j)))
            {
                for(int k=0;k<n;k++)
                {
                    if((i>>k)&1)
                    {
                        dp[i|(1<<j)][j]=max(dp[i|(1<<j)][j],dp[i][k]+a[j]+c[k][j]);
                    }
                }
            }
        }
    }
    ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        cnt=0;
        now=i;
        while(now)
        {
            if(now&1)
            {
                cnt++;
            }
            now>>=1;
        }
        if(cnt==m)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
    }
    printf("%lld\n",ans+1);
    return 0;
}
