#include<bits/stdc++.h>
using namespace std;
int sumb[100005],sumg[100005];
bool ismale[100005];
int n;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>ismale[i];
        sumb[i]=sumb[i-1];
        sumg[i]=sumg[i-1];
        if(ismale[i])
        {
            ++sumb[i];
        }else
        {
            ++sumg[i];
        }
    }
    for(int i=n;i>=0;--i)
    {
        int bx=0,gx=0;
        for(int j=1;j<=n-i;++j)
        {
            int k=i+j;
            bx=sumb[k]-sumb[j];
            gx=sumg[k]-sumg[j];
            if(bx==gx)
            {
                cout<<i;
                return 0;
            }
        }
    }
}
