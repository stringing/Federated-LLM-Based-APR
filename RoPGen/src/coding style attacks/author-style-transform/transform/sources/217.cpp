#include <bits/stdc++.h>
using namespace std;

int s[100][100],a[100][100];
int main(int argc, char *argv[]) {
    freopen("max_sub_sum.in","r",stdin);
    freopen("max_sub_sum.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    s[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        s[i][0]=s[i-1][0]+a[i][0];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    return 0;
}
