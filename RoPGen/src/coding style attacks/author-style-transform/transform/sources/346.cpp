#include<bits/stdc++.h>
using namespace std;
int n;
int stonea[15];
int stoneb[15];
bool flag;
long long ans=1000000000000;
void dfs(int now,int a,int b)
{
    if(now=n&&flag==true)
    {
        if(max(a,b)-min(a,b)<ans)
        {
            ans=max(a,b)-min(a,b);
        }
        return;
    }
    if(now>n)
    {
        return;
    }
    
    dfs(now+1,a*stonea[now],b);
    dfs(now+1,a,b*stoneb[now]);
    dfs(now+1,a,b);
    
}
int main()
{
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>stonea[i];
        cin>>stoneb[i];
    }
    dfs(1,1,1);
    cout<<ans;
    return 0;
}
