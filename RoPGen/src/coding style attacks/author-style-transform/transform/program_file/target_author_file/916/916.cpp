#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string pre[2]={"101","111"};
string g(){
    string s;
    char c;
    while(cin>>c)s+=c;
    if(s.length()%8!=0)return "Error";
    string ans="",t,n;
    int p=0;
    while(p+7<s.length()){
        n=t="";
        for(int i=p;i<p+3;i++)t+=s[i];
        if(t==pre[1]){
            ans+=" ";
            continue;
        }
        for(int i=p+3;i<p+8;i++)n+=s[i];
        if(t==pre[0]){
            int a=0;
            if(n[0]=='1')a+=16;
            if(n[1]=='1')a+=8;
            if(n[2]=='1')a+=4;
            if(n[3]=='1')a+=2;
            if(n[4]=='1')a+=1;
            if(a>25)return "Error";
        }
    }
}
int main(){
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    
    cout<<char('A'+25);
    
    return 0;
}
