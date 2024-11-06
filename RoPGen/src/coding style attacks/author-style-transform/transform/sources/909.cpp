#include <cstdio>
#include <iostream>
using namespace std;
int a[105];
int cnt[20005];
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    for(int a=0;a*a<=n;a++){
        for(int b=0;a*a+b*b<=n;b++){
            for(int c=0;a*a+b*b+c*c<=n;c++){
                   int d=n-a*a+b*b+c*c;
                    if(a*a+b*b+c*c+d*d==n){
                        cout<<a<<" "<<b<<" "<<c<<" "<<d;
                    }
                }
            }
        }
    return 0;
}
