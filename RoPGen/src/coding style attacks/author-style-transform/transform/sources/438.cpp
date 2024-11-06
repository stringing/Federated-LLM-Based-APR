#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int x=0,num=0;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            num++;
        }else{
            if(num>x){
              x=num;
            }
            num=0;
        }
    }
    cout<<x<<endl;
    return 0;
}
