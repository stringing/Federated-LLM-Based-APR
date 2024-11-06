#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    int n,x=0;
    string s,c[100];
    cin>>n;
    getchar();
    while(n--){
        getline(cin,s);
        getchar();
        getchar();
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I'){
                s[i]-=32;
            }
        }for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                x++;
            }
            c[x]+=s[i];
        }for(int i=0;i<=x+1;i++){
            if(c[i]=="?") cout<<"!"<<" ";
            else if(c[i]=="me") cout<<"you"<<" ";
            else if(c[i]=="I") cout<<"you"<<" ";
            else if(c[i]=="can"&&c[i+1]=="you") cout<<"I"<<" "<<"can"<<" ";
            else if(c[i]=="could"&&c[i+1]=="you") cout<<"I"<<" "<<"could"<<" ";
            else cout<<c[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
