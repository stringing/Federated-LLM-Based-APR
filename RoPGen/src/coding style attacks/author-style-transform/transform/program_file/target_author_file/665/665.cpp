#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t,n,x,y,p,o;
    cin>>t;
    int degree[t+1][100000];
    for(int j=1;j<=t;j++)
    {
        p=0;
        cin>>n;
        vector<int> G[n+1];
        for(int i=0;i<=n;i++)
        {
            degree[j][i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
            degree[j][x]++;
        }
        for(int i=1;i<n;i++)
        {
            o=0;
            for(int v=0;v<G[i].size();v++)
            {
                if(degree[j][i]<degree[j][G[i][v]])
                {
                    o++;
                    break;
                }
            }
            if(o==0)
            {
                p++;
            }
        }
        cout<<p<<endl;
    }
   
}
