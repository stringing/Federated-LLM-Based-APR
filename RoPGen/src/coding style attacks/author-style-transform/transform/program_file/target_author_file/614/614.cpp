#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    int a[1005];
    string num;
    int len;
    cin >>num;
    len = num.size();
    for(int i = 0; i < len; i++){
        a[i] = num[len - 1 - i] - '0';
    }
    a[0] += 2018;
    for(int i = 0; i < len; i++){
        a[i + 1] += a[i] / 10;
        a[i] % 10;
    }
     while(a[len]){
        a[len + 1]+= a[len] / 10;
        a[len] %= 10;
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}
