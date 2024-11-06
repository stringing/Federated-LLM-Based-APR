#include <bits/stdc++.h>
using namespace std;
string a[1000];
int n;
int m=0;
void little(string x){
    string m;
    for(int i = 0;i < x.size();i++){
        m=x;
        if(x[i]!='I'&&x[i]>64&&x[i]<91){
            x[i]=m[i]+32;
        }
        
    }
}
int main(){
    cin>>n;
    for(int i = 0;i < n;i++){
        while(a[m]=='?'||a[m]=='!')
        {
            cin>>a[m];
            m++;
            little(a);
            cout<<a;
        }
       
    }
}
