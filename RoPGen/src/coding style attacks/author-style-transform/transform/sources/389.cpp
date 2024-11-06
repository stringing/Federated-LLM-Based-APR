#include <bits/stdc++.h>
using namespace std;
string a,b;
int n;
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
        cin>>a;
        little(a);
        cout<<a<<" ";
    }
}
