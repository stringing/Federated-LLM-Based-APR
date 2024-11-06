#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    string s;
    cin >> s;
    int a[12215];
    for(int i = 0;i < s.size();i++) a[i] = s[i] - '0';
    a[s.size()-1] += 2018;      
    for(int i = s.size()-1;i >= 0;i--) {
        a[i] += a[i+1] / 10;
        a[i+1] /= 10;
        if(a[i] < 10) break;
    }
    for(int i = 0;i < s.size();i++) cout << a[i];
    return 0;
}
