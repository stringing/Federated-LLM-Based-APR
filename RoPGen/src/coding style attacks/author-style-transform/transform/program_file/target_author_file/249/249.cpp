#include <bits/stdc++.h>
using namespace std;
int n,len1=1,len2=1,a[10000000],b[10000000];
int main(){
    freopen("factorial.in","r",stdin);
    freopen("factorial.out","w",stdout);
    b[1] = 2;
    cin >> n;
    for(int i=2; i<=n; i++){
        for(int j=0; j<len1; j++){
            b[j] = b[j] * i;
        }
        for(int j=0; j<len1; j++){
            b[j+1] = b[j+1] + b[j] / 10;
            b[j] = b[j] % 10;
        }
        len2 = max(len1,len2);
        for(int j=0; j<len2; j++){
            a[j] = a[j] + b[j];
            a[j+1] = a[j+1] + a[j] / 10;
            a[j] = a[j] % 10;
        }
        while(a[len1]){
            a[len1+1] = a[len1+1] + a[len1] / 10;
            a[len1] = a[len1] % 10;
            len1 = len1 + 1;
        }
    }
    for(int i=len2-1; i>=0; i--){
        cout << a[i];
    }
    return 0;
}
