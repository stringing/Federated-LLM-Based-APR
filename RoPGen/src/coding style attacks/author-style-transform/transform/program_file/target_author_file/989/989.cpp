#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,d[10000];
    int b=0,c=0,e=0;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]!=' '){
            b++;
            d[e]=a[i];
        }else{
            i++;
            continue;
        }
        e++;
        if(b>c){
            c=b;
            e=0;
        }
        b=0;
    }
    cout<<fixed<<d;
}
