#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
    while(t--){
        int i=0,x=0;
        string s;
        string ma[100]={""};
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i]!='I'&&s[i]>='A'&&s[i]<='Z'){
                s[i]+=32;
            }
        }
        while(i<s.size()){    
            if(s[i]!=' ') ma[x]+=s[i];
            else x++;
            i++;
        }
        for(int i=0;i<x;i++){
            if(ma[i]=="?"){
                cout<<"! ";
            }else if(ma[i]=="I"||ma[i]=="me"){
                cout<<"you ";
            }else if(ma[i]=="can"&&ma[i+1]=="you"){
                cout<<"I can ";
            }else if(ma[i]=="could"&&ma[i+1]=="you"){
                cout<<"I could ";
            }else{
                cout<<ma[i]<<" ";
            }
        }
        cout<<"!"<< endl;
    }
    return 0;
}
