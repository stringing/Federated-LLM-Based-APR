#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string num1, num2;
int a1[105], a2[105], len1, len2 = 2018;
int main() {
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    cin >> num1 >> num2;
    len1 = num1.size();
    for (int i = 0; i < len1; i++) {
        a1[i] = num1[len1 - 1 - i] - '0';
    }
    len2 = num2.size();
    for (int i = 0; i < len2; i++) {
        a2[i] = num2[len2 - 1 - i] - '0';
    }
    len1= max(len1,len2);
    for(int i = 0; i < len1; i++){
        a1[i] += a2[i];
    }
    for(int i = 0; i < len1; i++){
        a1[i+1] += a1[i]/10;
        a1[i] %=10;
    }
    while(a1[len1]){
        a1[len1 + 1]+=  a1[len1] / 10;
        a1[len1] %= 10;
        len1++;
    }
    for (int i = len1 - 1; i >= 0; i--) {
        cout << a1[i]+2018;
    }
    cout << endl;
    return 0;
}
