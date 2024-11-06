#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y) {
    int sumx = 0,sumy = 0;
    while(x) {
        sumx += x % 10;
        x /= 10;
    }
    while(y) {
        sumy += y % 10;
        y /= 10;
    }
    if(sumx != sumy)
        return sumx < sumy;
    else
        return x < y;
}
int main() {
    int n;
    int a[111];
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    sort(a,a+n,cmp);
    for(int i = 0;i < n;i++)
        cout << a[i] << " ";
    return 0;
}
