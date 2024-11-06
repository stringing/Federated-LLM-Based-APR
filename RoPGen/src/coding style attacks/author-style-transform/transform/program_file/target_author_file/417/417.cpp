#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    char a[s.size()];
    int ine=0,nub=0;
    if(s[i]==" "){
        a=s.substr(0,s.find(" ")-1);

    }
    for(int i=0;i<s.size();i++){
        if(s[i-1]==" "&&s[i]!=" "){
            if(a.size<s.find(" ")-1-i){
                    a=s.substr(0,i-1);
            }
        }

    }for(int i=0;i<a;i++){
        cout<<a[i];    
    }
    return 0;
}
