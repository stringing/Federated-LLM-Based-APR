#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
map<ll,set<int> > cnt;
bool vis[100005];
int n;
int ans=0;
int stop=0;
void arrive(ll x)
{
    int h=cnt[x].size();
    if(stop>x)
    {
        ans+=(stop-x)*4;
    }else
    {
        ans+=(x-stop)*5;
    }
    stop=x;
    ans+=3;
    ans+=h*2;
}
int main()
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        cnt[a[i]].insert(i);
    }
    int now=1;
    while(now<n)
    {
        if(vis[now])
        {
            ++now;
            continue;
        }
        for(auto it:cnt[a[now]])
        {
            vis[it]=true;
        }
        arrive(a[now]);
        ++now;
    }
    arrive(0);
    cout<<ans-3;
}
