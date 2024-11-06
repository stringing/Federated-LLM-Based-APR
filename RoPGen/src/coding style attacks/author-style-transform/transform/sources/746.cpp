#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x=0;
        string f[110]={},s="";
        getline(cin,s);
        for(int j=0;j<s.size();j++){
            if(isupper(s[j])&&s[j]!='I') s[j]+="a"-"A";
            if(s[j]=='?') s[j]='!';
            if(s[j]!=' ') f[x]+=s[j];
            if(s[j+1]==s.size()||s[j+1]==' ') x++;
        }
        for(int j=0;j<=x;j++){
            if((f[j]=="can"||f[j]=="could")&&f[j+1]=="you"){
                cout<<"I "<<f[j]<<" ";
                j++;
            }
            else if(f[j]=="I"||f[j]=="me") cout<<"you ";
            else cout<<f[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
