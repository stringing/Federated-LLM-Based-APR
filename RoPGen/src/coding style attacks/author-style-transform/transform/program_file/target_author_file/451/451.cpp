#include<bits/stdc++.h>
using namespace std;
const int Maxn=20;
const int Maxk=20*19;
int Ar[Maxn];
int c[Maxk][Maxk];
int dp[1<<Maxn][Maxn];
int bitcount(int x)
{
    int cnt=0;
    while(x)
    {
        x-=x&(-x);
        cnt++;
    }
    return cnt;
}
int main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Ar[i]);
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%d",&c[x-1][y-1]);
    }
    for(int i=0;i<n;i++)
    {
        dp[1<<i][i]=Ar[i];
    }
    int ans=-0x3f;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i!=0)
            {
                continue;
            }
            for(int k=0;k<n;k++)
            {
                if((1<<k)&i==0)
                {
                    continue;
                }
                dp[i|(1<<j)][j]=max(dp[i|(1<<j)][j],dp[i][k]+Ar[j]+c[k][j]);
            }
            if(bitcount(i)==m-1)
            {
                ans=max(ans,dp[i|(1<<j)][j]);
            }
        }
    }
    
    printf("%d\n",ans);
    return 0;
}
