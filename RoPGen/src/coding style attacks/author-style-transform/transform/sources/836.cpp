#include<bits/stdc++.h>
using namespace std;
string s;
int a[50000];
int main(){
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    string in;
    while(cin>>in)
        s.append(in);
    int flag=s[0]-'0';
    int sum=0;
    cout<<sqrt(s.length())<<" ";
    for(int i=0;i<s.length();i++){
        if(s[i]!=char((int)flag+'0')){
            flag=flag^1;
            cout<<sum<<" ";
            sum=0;
        }else{
            sum++;
            continue;
        }
    }
    return 0;
}
