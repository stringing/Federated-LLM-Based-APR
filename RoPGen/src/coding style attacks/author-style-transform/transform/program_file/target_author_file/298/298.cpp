#include<bits/stdc++.h>
using namespace std;
string th(string a){
    for(int i=0;i<a.size();i++){
        if(a[i]>='A'&&a[i]<='Z'&&a[i]!='I') a[i]=char(a[i]+32);
    }
    while(a.find("can you")!=string::npos){
        a.replace(a.find("can you"),a.find("can you")+7,"I can");
    }
    while(a.find("could you")!=string::npos){
       a.replace(a.find("could you"),a.find("could you")+9,"I could");
    }
    while(a.find("I")!=string::npos){
       a.replace(a.find("I"),a.find("I")+1,"you");
    }
    while(a.find("me")!=string::npos){
       a.replace(a.find("me"),a.find("me")+2,"you");
    }
    while(a.find("?")!=string::npos){
       a.replace(a.find("?"),a.find("?")+1,"!");
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    string a;
    for(int i=1;i<=n+1;i++){
        getline(cin,a);
        cout<<th(a)<<endl;
    }
}
