#include <bits/stdc++.h>
using namespace std;
int a1[200000], a2[200000], len1, len2;
int main(){
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a[100000] = {1}, len = 1;
        for(int j = 2; j <= i; j++){
            for(int k = 0; k < len; k++)
                a[k] *= j;
            for(int k = 0; k < len; k++){
                a[k + 1] += a[k] / 10;
                a[k] %= 10;
            }
            while(a[len]){
                a[len + 1] += a[len1] / 10;
                a[len] %= 10;
                len++;
            }
        }
        len2 = len;
        len1 = max(len1, len2);
        for(int i = 0; i < len1; i++)
            a1[i] += a[i];
        for(int i = 0; i < len1; i++){
            a1[i + 1] += a1[i] / 10;
            a1[i] %= 10;
        }
        while(a1[len1]){
            a1[len1 + 1] += a1[len1] / 10;
            a1[len1] %= 10;
            len1++;
        }
    }
    for (int i = len1 - 1; i >= 0; i--) {
        cout << a1[i];
    }
    cout << endl;
    return 0;
}
