






































#include<bits/stdc++.h>
using namespace std;
int sumb[100005],sumg[100005],sum[100005];
bool ismale[100005];
set<int> se;
int n,ans;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>ismale[i];
        if(!ismale[i])
        {
            sum[i]=sum[i-1]-1;
        }else
        {
            sum[i]=sum[i-1]+1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(se.count(sum[i]))
        {
            continue;
        }
        se.insert(sum[i]);
        int now=sum[i];
        for(int j=n;j>i;--j)
        {
            if(sum[j]==now)
            {
                ans=max(ans,j-i);
            }
        }
    }
    cout<<ans;
}
