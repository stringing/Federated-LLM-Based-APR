#include<bits/stdc++.h>
using namespace std;
int f[500][500];
int a[500]; 
int c[500][500];
int count(int num)
{
    int cnt=0;
    while(num)
    {
        if(num&1)
            cnt++;
        num>>=1;
    }
    return cnt;
}
int main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
    {
        int x,y,C;
        cin>>x>>y>>C;
        c[x][y]=C;
    }
    for(int i=0;i<n;i++)
        f[1<<i][i]=a[i];
    for(int i=0;i<(1<<n)-1;i++)
        for(int j=0;j<n;j++)
            if((i&(1<<j)))
                for(int k=0;k<n;k++)
                    if(i&(1<<k))
                        f[i|(1<<j)][j]=f[i][k]+a[j]+c[k][j];
    int ans=-1;
    for(int i=0;i<(1<<n)-1;i++)
        if(count(i)==m)
            for(int j=0;j<n;j++)
                ans=max(ans,f[i][j]);
    cout<<ans;
    return 0;
}

