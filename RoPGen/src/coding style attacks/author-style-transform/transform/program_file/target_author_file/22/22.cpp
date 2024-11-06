#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    int n,m=0;
    char a,num;
    string s;
    cin>>s;
    n=s.size();
    cout<<n<<" ";
    m=1;
    for(int j=0;j<n;j++)
    {
        a=s[j];
        if(j==0)
            {
                num=a;
            }
            else
            {
                if(num==a)
                {
                    m++;
                }
                else
                {
                    cout<<m<<" ";
                    m=1;
                    num=a;
                }
            }
        }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
            if(num==a)
            {
                m++;
            }
            else
            {
                cout<<m<<" ";
                m=1;
                num=a;
            }
        }
    }
    cout<<m;
    return 0;
}
