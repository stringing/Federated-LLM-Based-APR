#include<bits/stdc++.h>
using namespace std;
int n;
int flor;
long long a[100005];
int od; 
long long mf; 
int main(){
    freopen("elevator.out", "w", stdout);
    freopen("elevator.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    for (int i = 1; i <= n; i++) {
        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            if (a[j] == a[i]) {
                flag = 0;
                break;
            }
        }
        od += flag;
        mf = max(mf, a[i]);
    }
    cout << 1ll * mf * (4 + 5) + 1ll * od * 3 + 1ll * n * 2;
    return 0;
}
