#include<iostream>
#include<string>
using namespace std;
int main(){
    string t,s="";
    int sum=1;
    char op='1';
    cin>>t;
    cout<<t.size()<<" ";
    while(cin>>t){
        s+=t;
    }for(int i=0;i<s.size();i++){
         if(s[i]==op){
             sum++;
         }else{
            op=s[i];
            cout<<sum<<" ";
            sum=1;
         }
    }
    cout<<sum<<" ";
    return 0;
}
