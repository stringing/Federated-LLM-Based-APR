#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x=0;
    cin>>n;
    getchar();
    string a[1999]={};
    while(n--){
        for(int i=0;i<1999;i++){
            a[i]="";
        }
        x=0;
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
                a[x]+=s[i];
            }else{
                x++;
            }
        }
        for(int i=0;i<=x;i++){
            if(a[i]=="can"||a[i]=="could"){
                if(a[i+1]=="you"){
                    cout<<"I "<<a[i]<<" ";
                }
            }
            else if(a[i]=="me"||a[i]=="I"){
                cout<<"you ";
            }
            else{
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
}
