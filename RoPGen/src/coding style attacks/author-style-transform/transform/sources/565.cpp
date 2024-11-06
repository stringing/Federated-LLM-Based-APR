#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int longest=0,lo=0;
    string lon;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]!=' '){
            lo++;
        }else{
            lo=0;
        }
        if(lo>longest){
            longest=lo;
            lon=a.substr(i-lo,lo);
        }
    }
    for(int i=0;i<lon.size();i++){
        cout<<lon[i];
    }
}
