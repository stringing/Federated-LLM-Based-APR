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
    for(int i = 2;i < s.size();i++) {
        a[s.size()-i] += a[s.size()-i+1] / 10;
        a[s.size()-i+1] /= 10;
        if(a[s.size()-i] < 10) break;
    }
    for(int i = 0;i < s.size();i++) {
        cout << a[i];
    }
    return 0;
}
