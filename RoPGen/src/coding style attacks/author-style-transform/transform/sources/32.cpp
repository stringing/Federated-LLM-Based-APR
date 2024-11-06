#include<bits/stdc++.h>
#define MAX 205
using namespace std;
int main()
{
    int T,n,i,j,p[MAX];
    freopen("elevator.in", "T", stdin);
    cin >> T;
    while(T--)
    {
        freopen("elevator.in", "n", stdin);
        cin >> n;
        for(i=1;i<=n;i++)
        {
            freopen("elevator.in", "p[i]", stdin);
            cin >> p[i];
        }
        sort(p+1,p+n+1);
        int time=5*p[n]+4*p[n];
        for(i=0;i<=150;i++)
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
              time+=2;
            time+=num*2;
        }
        freopen("elevator.out", "time", stdin);
        cout << time;
    }
    return 0;
}
