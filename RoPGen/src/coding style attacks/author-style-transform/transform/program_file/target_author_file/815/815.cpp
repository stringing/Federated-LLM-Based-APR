#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[30];
int x[30],y[30],c[30];
int cc[30][30];
long long ans;
long long dp[1000000][30];
int check(int w)
{
    int sum=0;
    int W=w;
    while(W!=0)
    {
        sum+=W%2;
        W/=2;
    }
    return sum;
}
int main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        cin>>x[i]>>y[i]>>c[i];
        cc[x[i]][y[i]]=c[i];
    }
    for(int i=0;i<=(1<<n)-1;i++)
    {
        if(check(i)>=m) continue;
        for(int j=1;j<=n;j++)
        {
            if((i&(1<<(j-1)))!=0) continue;
            for(int k=0;k<=n;k++)
            {
                if(j==k) continue;
                if(((i&(1<<(k-1)))!=0)&&(k!=0)) continue;
                dp[(i|(1<<(j-1)))][j]=max(dp[(i|(1<<(j-1)))][j],dp[i][k]+cc[k][j]+a[j]);
                ans=max(ans,dp[(i|(1<<(j-1)))][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
