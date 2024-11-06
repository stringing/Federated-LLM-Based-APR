#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    int b=0,c=0,e,d;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]!=' '){
            b++;
        }
        while(a[i]==' '){
            if(b>c){
            c=b;
            d=i;
            while(a[d]!=' '){
                d--;
            }   
        }
        b=0;
            i++;
            continue;
        }
    }
    e=d+1;
    while(a[e]!=' '){
        cout<<a[e];
        e++;
    }
}
