#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdio.h>  
using namespace std;
int n, m, a[1000001], b;
int fin(int b)
{
    int l = 0, r = m - 1, mi;
    while (l <= r)
    {
        mi = (r + l)/2;
        if(a[mi] == b)
        {
            return 1;
        }
        else if(a[mi] < b)
         {
            l = mi+1;
        }
        else
        {
            r = mi - 1;
        }
    }
    return 0;
}
int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    scanf("%d%d",&m,&n);
    for (int i = 0 ; i < m ; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+m);
    for (int j = 0 ; j < n ; j++)
    {
        scanf("%d", &b);
        if(fin(b) == 1)
        {
            printf("YES/n");
        }
        else
        {
            printf("NO/n");
        }
    }
    return 0;
}
