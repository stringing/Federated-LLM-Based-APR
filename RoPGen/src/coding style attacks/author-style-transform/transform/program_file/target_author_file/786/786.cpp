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
        }else{
            i++;
            continue;
        }
        e++;
        if(b>c){
            c=b;
            d=i;
            while(a[d]!=' '){
                d--;
            }
            e=d+1;
        }
        b=0;
    }
}
