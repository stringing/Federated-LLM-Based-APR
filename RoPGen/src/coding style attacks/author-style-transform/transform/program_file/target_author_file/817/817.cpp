#include <bits/stdc++.h>
using namespace std;
int sb(int a,int b,int c,int d)
{
    int aa = a * a;
    int bb = b * b;
    int cc = c * c;
    int dd = d * d;
    return aa + bb + cc + dd;
}
int main() 
{
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    for(int a = 1; a <= 114514; a++)
    {
        for(int b = 1; b <= 114514; b++)
        {
            for(int c = 1; c <= 114514; c++)
            {
                 int d = ;
                 if(sb(a,b,c,d) == n)
                 {
                     cout << a << " " << b << " " << c << " " << d;
                 }
            }
        }
    }
}
