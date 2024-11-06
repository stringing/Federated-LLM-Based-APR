#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    getchar();
    int x=0;
    string a[1005]={};
    while(n--){
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
            if(a[i]=="can"||a[i]=="could"&&a[i+1]=="you"){
                cout<<"I "<<a[i]<<" ";
                i++;
            }else if(a[i]=="I"||a[i]=="me"){
                cout<<"you ";
            }else{
                cout<<a[i]<<" ";
                
            }
            
        }
       cout<<endl;
    }
  
    return 0;
}

