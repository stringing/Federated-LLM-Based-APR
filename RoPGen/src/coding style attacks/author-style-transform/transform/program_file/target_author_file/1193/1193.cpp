#include <iostream>
#include <algorithm>
using namespace std;
int a[106000];
bool cmp (int x, int y)
{
    int xsum = 0, ysum = 0;
    while (x > 0)
    {
        xsum = xsum + x % 10;
        x /= 10;
    }
    while (y > 0)
    {
        ysum = ysum + y % 10;
        y /= 10;
    }
    if (xsum != ysum)
    {
        return xsum < ysum;
    }
    else
    {
        return x < y;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
