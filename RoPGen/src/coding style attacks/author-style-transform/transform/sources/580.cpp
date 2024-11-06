#include<bits/stdc++.h>
using namespace std;
int n;
int flor;
int ans;
int main(){
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        bool flag = 0;
        while (flor != a) {
            if (a > flor) {
                flor++;
                ans += 5;
            }  
            else {
                flor--;
                ans += 4;
            }
            flag = 1;
        }
        ans += flag * 3;
        ans += 2;
    } 
    ans += flor * 4;
    cout << ans;
    return 0;
}
