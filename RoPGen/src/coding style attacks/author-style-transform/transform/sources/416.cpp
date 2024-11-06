#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
string cheng(int x,string num1){
    int a[4000];
    int len = num1.size();
    for (int i = 0; i < len; i++) {
        a[i] = num1[len - 1 - i] - '0';
    }
    for (int i = 0; i < len; i++) {
        a[i] *= x;
    }
    for (int i = 0; i < len; i++) {
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    while(a[len]){
        a[len+1]+=a[len]/10;
        a[len]%=10;
        len++;
    }
    string num2="";
    for (int i = len - 1; i >= 0; i--) {
        num2+=(a[i]+'0');
    }
    return num2;
}
string jiecheng(int n){
    string sum="1";
    for(int i=2;i<=n;i++)
    {
        sum=cheng(i,sum);
    }
    return sum;
}
int a1[10005], a2[10005], len1, len2;
string jia(string num1,string num2) {
    len1 = num1.size();
    for (int i = 0; i < len1; i++) {
        a1[i] = num1[len1 - 1 - i] - '0';
    }
    len2 = num2.size();
    for (int i = 0; i < len2; i++) {
        a2[i] = num2[len2 - 1 - i] - '0';
    }
    len1=max(len1,len2);
    for(int i=0;i<len1;i++){
        a1[i]+=a2[i];
    }
    for(int i=0;i<len1;i++){
        a1[i+1]+=a1[i]/10;
        a1[i]%=10;
    }
    while(a1[len1]){
        a1[len1+1]+=a1[len1]/10;
        a1[len1]%=10;
        len1++;
    }
    string num="";
    for (int i = 0; i <len1; i++) {
        num+=(a1[i]+'0');
    }
    return num;
    memset(a1,0,sizeof(a1));
    memset(a2,0,sizeof(a2));
}
int main() {
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    int n;
    cin>>n;
    string SUM="";
    for(int i=1;i<=n;i++){
        SUM=jia(SUM,jiecheng(i));
    }
    cout<<SUM<<endl;
    return 0;
}
