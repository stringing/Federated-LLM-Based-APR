#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int sum=0,ans=0;
   int t=1;
    
   for(int i=s2.size()-1;i>=0;i--){
       sum+=(s2[i-1]-'0')*t;
       t++;
   }
    

    
    t=1;
     int tmp;
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]!='?'){
             ans+=(s1[i-1]-'0')*t;
        }else{
            tmp=t;
        }
       t++;
       
        
    }

    
    int a=sum-ans;
    
        if(a%tmp==0&&a/tmp>=0&&a/tmp<10){
            cout<<a/tmp;
        }else{
            cout<<"Lier!"<<endl;
        }
    
    

    return 0;
}
