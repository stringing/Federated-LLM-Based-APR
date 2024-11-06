#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int const N=1e6+10;
int a[N];
int main()
{
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+m);
    string Y="YES",N="NO";
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(binary_search(a+1,a+1+n,x))
        {
            printf("%s\n",Y);
        }
        else
        {
            printf("%s\n",N);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


