#include <algorithm>
#include <iostream>
using namespace std;
int num[10005];
int sum(int m)
{
    int s = 0;
    while(m >= 0)
    {
        s += m % 10;
        m /= 10;
    }
    return s;
}
bool cmp(int x,int y)
{
    if(sum(x) != sum(y))    return sum(x) < sum(y);
    else   return x < y;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num,num + n,cmp);
    for(int i = 0; i < n; i++)
    {
        cout << num[i] << endl;
    }
}
