#include <iostream>
#include <algorithm>
using namespace std;
long long a[100000];
long long cnt[100000];
int main()
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*5+3+cnt[i]*2;
    }
    cout<<sum+a[n]-0*4;
    return 0;
}
