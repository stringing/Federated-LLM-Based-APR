#include <bits/stdc++.h>
using namespace std;
int n,m,a[51][51];
int Max=-1;
void input()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
}
int work()
{
    int s=0,Max=-1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int w=1; w<=n-i; w++)
            {
                for(int e=1; e<=m-j; e++)
                {
                    s=0;
                    for(int ww=i; ww<=ww+w-1; ww++)
                    {
                        for(int ee=j; ee<=ee+e-1; ee++)
                        {
                            s+=a[ww][ee];
                        }
                    }
                    cout<<s<<endl;
                    if(s>Max)
                    {
                        Max=s;
                    }
                }
            }
        }
    }
    return Max;
}
int main()
{
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    input();
    cout<<work()<<endl;
    return 0;
}

