#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
long long a[100000];
long long cnt[100000];
map<int,int>m;
int main()
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(m[i]>1)
        {
            sum+=(m[i]-1)*2; 
        }
        else
        {
            sum+=(a[i]-a[i-1])*5+3+2; 
        }
        
    }
    cout<<sum+(a[n]-0)*4;
    return 0;
}
