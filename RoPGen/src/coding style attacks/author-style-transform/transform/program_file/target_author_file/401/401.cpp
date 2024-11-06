#include<bits/stdc++.h>
using namespace std;
string a[205];
int main()
{
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    cin>>a[0];
    int n=a[0].size();
    for(int i=1;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<n<<' ';
    int index=a[0][0],sum=0,s[2]={0,0};
    bool cmp=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]==index)
            {
                ++sum;
            }else
            {
                s[(int)(cmp)]+=sum;
                cmp=!cmp;
                sum=1;
                index=a[i][j];
            }
        }
    }
    s[(int)(cmp)]+=sum;
    if(s[0]!=n*n)
    {
        cout<<"0 ";
    }
    index=a[0][0],sum=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]==index)
            {
                ++sum;
            }else
            {
                cout<<sum<<' ';
                sum=1;
                index=a[i][j];
            }
        }
    }
    cout<<sum;
}
