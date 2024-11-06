#include<bits/stdc++.h>
using namespace std;
void process(){
    long long n;
    cin >> n;
    long long a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n);
    long long ans = 9 * a[n - 1];
    ans += 2 * n;
    for(int i = 0;i < n;i++){
        if(i != 0){
            ans += 3;
        }else if(a[i] != a[i - 1]){
            ans += 3;
        }else{
            ans += 0;
        }
    }
    cout << ans << endl;
}
int main(){
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    process();
    return 0;
}
