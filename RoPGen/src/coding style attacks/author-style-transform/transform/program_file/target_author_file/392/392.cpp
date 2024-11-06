#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
const int N=1000+10;
int a[N];
int main(){
    freopen(a,0,sizeof(a));
    string num;
    cin >> num;
    int len = num.length();
    for (int i = 1; i <= len; i++){
        a[i] = num[len - i] - '0';
    }
    a[1] += 2018;
    for (int i = 1; i <= len; i++){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[len + 1]){
        len++;
        a[len + 1] += a[len] / 10;
        a[len] %=10;
    }
    for (int i = len; i >= 1; i--){
        cout << a[i];
    }
    return 0;
}
