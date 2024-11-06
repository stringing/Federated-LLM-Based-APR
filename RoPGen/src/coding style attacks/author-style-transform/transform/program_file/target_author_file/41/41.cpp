#include<bits/stdc++.h>
#define MAX 100000

using namespace std;
int main()
{
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    long long T,n,i,j,p[MAX];
    cin >> T;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    sort(p+1,p+n+1);
    long long time=5*p[n]+4*p[n];
    for(i=0;i<=1000;i++)
    {
        long long num=0,flag=0;
        for(j=1;j<=n;j++)
        {
            if(p[j]==i)
            {
                flag=1;
                num++;
            }
        }
        if(flag == 1)
            time+=3;
        time+=num*2;
    }
    cout << time;
    return 0;
}
