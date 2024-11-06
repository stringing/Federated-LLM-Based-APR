#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x=0;
    scanf("%d",&n);
    string f[1000+10]={};
    while(n--){
        x=0;
        memset(f,0,sizeof(f));
        string s;
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I'){
                s[i]+=32;
            }
            if(s[i]=='?'){
                s[i]='!';
            }
            if(s[i]!=' '){
                f[x]+=s[i];
            }else x++;
        }
        for(int i=0;i<=x;i++){
            if(f[i]=="can"||f[i]=="could"&&f[i+1]=="you"){
                cout<<"I "<<f[i]<<" ";
            }
            else if(f[i]=="I"||f[i]=="me"){
                cout<<"you ";
            }else cout<<f[i]<<" ";
        }
        cout<<endl;
    }
}
