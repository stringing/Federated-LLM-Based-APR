#include<bits/stdc++.h>
using namespace std;
long long sum, n;
map <long long, int> m;
int main() {
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        sum += 9;
        sum += 3;
        sum += m[(*it)] * (long long)2;
    }
    cout << sum << endl;
    return 0;
}
