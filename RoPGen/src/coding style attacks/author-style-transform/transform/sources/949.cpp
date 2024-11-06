#include<bits/stdc++.h>
#define MAX 205
freopen("elevator.in", "r", stdin);
freopen("elevator.out", "w", stdin);
using namespace std;
int main()
{
    int T,n,i,j,p[MAX];
    cin >> T;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    sort(p+1,p+n+1);
    int time=5*p[n]+4*p[n];
    for(i=0;i<=1000;i++)
    {
        int num=0,flag=0;
        for(j=1;j<=n;j++)
        {
            if(p[j]==i)
            {
                flag=1;
                num++;
            }
        }
        if(flag)
            time+=3;
            time+=num*2;
    }
    cout << time;
    return 0;
}
