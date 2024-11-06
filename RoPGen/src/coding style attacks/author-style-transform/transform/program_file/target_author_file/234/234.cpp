#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t,n,x,y;
    cin>>t;
    while(t--)
    {
        int ans=0;
        vector<int> G[1005];        
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            G[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            int h=G[i].size(),k=1;
            for(int j=0;j<G[i].size();j++)
            {
                if(h<G[G[i][j]].size())
                {
                    k=0;   
                }
            }
            if(k) 
            {
                
                ans++;
            }
        }
        cout<<ans-1;
    }
    return 0;
} 

