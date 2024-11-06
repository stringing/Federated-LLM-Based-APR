#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int sum (int x) {
    int ans = 0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
bool cmp (int x, int y) {
    if (sum(x)!=sum(y))
    {
        return sum(x)<sum(y);
    }
    if (x>y)
    {
        return x>y;
    }
    return x<y;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

