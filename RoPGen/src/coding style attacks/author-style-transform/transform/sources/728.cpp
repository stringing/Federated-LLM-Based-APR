#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005];
int main(){
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    int n;
    cin >> n;
    long long floor_now = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i <= n; i++){
        if(a[i] > floor_now){
            ans += (a[i] - floor_now) * 5;
        }
        if(floor_now == a[i]){
            ans += 2;
        }else{
            ans += 5;
        }
        floor_now = a[i];
    }
    floor_now = a[n];
    ans += floor_now * 4;
    cout << ans << endl;
    return 0;
}
