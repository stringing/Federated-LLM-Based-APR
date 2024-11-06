#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long n;
int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    cin >> n;
    if(n == 1) {
        cout << 0 << " " << 0 << " " << 0 << " " << 1;
    }
    for(long long i = 0; i*i <= n; i++){
        for(long long j = 0; i*i + j*j <= n; j++){
            for(long long k = 0; i*i + j*j + k*k < n; k++){
                int d = sqrt(n - i*i - j*j - k*k);
                if(d == n){
                    cout << d;
                }
            }
        }
    }
    return 0;
}
