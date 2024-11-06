#include<bits/stdc++.h>
using namespace std;
long long n, x, j, sum, num, last, a[100100];
int main(){
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while(j < n){
        x = a[j];
        num = 0;
        for(int i = j; i < n; i++){
            if(a[i] = x) num++;
            else break;
        } 
        sum = sum + 5 * (x - last) + num * 2 + 3;
        last = x;
        j = j + num;
    }
    sum = sum + a[n - 1] * 4;
    cout << sum << endl;
    return 0;
}
