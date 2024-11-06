#include<bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[100001],b[100001],c[100001];
long long dp[500005];
int main()
{
    freopen("noble.in","r",stdin);
    freopen("noble.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i]<=j&&j-a[i]>=c[i])
            {
                dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
            }else{
                dp[j]=dp[j];
            }
        }
    }
    cout<<dp[m];
    return 0;
} 
